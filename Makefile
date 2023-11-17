SRC 	=						\
src/Colorable.cpp				\
src/main.cpp					\
src/CommandLineArguments.cpp	\
src/GLDebug.cpp					\
src/GLException.cpp				\
src/GLUtils.cpp 				\
src/Shader.cpp 					\
src/Triangle.cpp				\
src/Window.cpp					\
src/Keyboard.cpp

OBJ =   $(patsubst src/%,obj/%,$(SRC:.cpp=.o))

CXX  =   g++
DEBUG   =   -ggdb3 -DDEBUG_MODE

RELEASE = -O2
SANITIZE	=	-fsanitize=address,undefined -fsanitize-recover=address,undefined
ANALYZER	=

# Uncomment this line if encountering compile-related issues with C++2b, C++2a, C++1z, C++1y or C++0x (C++ version is displayed by the Makefile).
WIP_STANDARD_MODE=NO_WIP_STANDARD

# Comment those two lines if you're using another compiler than g++ and clang++, and don't forget to set yourself the C++ standard you want in CXX_VERSION (or replace it in CXX_FLAGS below).
CXX_VERSION_ERROR	=	$(shell ./c++_latest_version.sh $(CXX) $(WIP_STANDARD_MODE) 2>&1)
CXX_VERSION	=	$(shell ./c++_latest_version.sh $(CXX) $(WIP_STANDARD_MODE) 2> /dev/null)

CXXFLAGS  +=  -Wall -Wextra -pedantic -fsigned-char -funsigned-bitfields -Wno-unused-parameter $(CXX_VERSION)
LDFLAGS	+=	-lGL -lglfw -lGLEW
LD_PRELOAD	=

NAME    =   opengl.out

.PHONY: all re
all: CXXFLAGS += $(RELEASE)
all: $(NAME)
re: fclean all

.PHONY: debug redebug
debug: CXXFLAGS += $(DEBUG)
debug: $(NAME)
redebug: fclean debug

.PHONY: sanitize resanitize
sanitize: CXXFLAGS += $(DEBUG) $(SANITIZE)
sanitize: LD_PRELOAD += -lasan -lubsan
sanitize: $(NAME)
resanitize: fclean sanitize

.PHONY: analyzer reanalyzer
analyzer: ANALYZER += on
analyzer: CXXFLAGS += $(DEBUG) -fanalyzer
analyzer: $(NAME)
reanalyzer: fclean analyzer

.PHONY: check_version
check_version:
	@echo -------------
	@echo -n "CXX : "
	@if [[ "$(CXX_VERSION)" == "" ]]; then	\
		echo 'Bad CXX version !';			\
		echo $(CXX_VERSION_ERROR);			\
		exit 1;								\
	fi

.PHONY: display_info
display_info:
	@$(CXX) --version | head -n 1
	@echo CXXFLAGS : $(CXXFLAGS)
	@echo LDFLAGS : $(LD_PRELOAD) $(LDFLAGS)
	@echo -------------

.PHONY: remove_old_analyzer
remove_old_analyzer:
	@if [[ "$(ANALYZER)" != "" ]]; then		\
		rm -f ./analyzer.log;				\
		echo "Removing old analyzer log.";	\
	fi

$(NAME): check_version display_info remove_old_analyzer $(OBJ)
	@$(CXX) $(OBJ) $(LD_PRELOAD) $(LDFLAGS) -o $(NAME)

obj/%.o: src/%.cpp
	@if [[ "$(ANALYZER)" != "" ]]; then						\
		$(CXX) -c $(CXXFLAGS) $< -o $@ 2>> ./analyzer.log;	\
	else													\
		$(CXX) -c $(CXXFLAGS) $< -o $@;						\
	fi

.PHONY: clean_vgcore
clean_vgcore:
	@echo Removing Core Dumped files.
	@rm -f vgcore.*
	@rm -f valgrind*.log.core.*

.PHONY: clean
clean: clean_vgcore
	@echo Removing temporary and object files.
	@rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	@echo Removing binary.
	@rm -f $(NAME)

.PHONY: help
help:
	@echo "Builds your C++ files and links GL, GLEW and GLFW libraries."
	@echo "Compiles using the latest C++ standard supported by your compiler (displayed in this Makefile log)."
	@echo "If you're running into issues not related to your own code, you should consider taking a look at the beginning of this Makefile, by uncommenting a line defining the WIP_STANDARD_MODE variable."
	@echo "This variable will disable the \"Working in progress\" C++ standards, as they can conflict with the headers because they're not fully standard-compliant."
	@echo "If you're using another compiler than g++ and clang++, you must take a look at the beginning of this Makefile again (read the comments)."
	@echo "To determine the latest C++ standard of your compiler, this Makefile uses a bash script which tests what standard flags are valid or not with your compiler, but only supports these two compilers."
	@echo "To know a bit more about C++ standards with this Makefile, simply execute \"./c++_latest_version.sh\" (adding -h or --help flag is also fine)."
	@echo "Enjoy the power of OpenGL :)"
