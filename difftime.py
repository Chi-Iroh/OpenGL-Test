#!/bin/python3

from typing import Tuple

def diffTimeSeconds() -> float:
    start = float(open(".time", "r").readline().strip())
    end = float(open(".time.end", "r").readline().strip())
    return end - start

diff = diffTimeSeconds()
hours = int(diff / 3600)
diff -= hours * 3600
minutes = int(diff / 60)
diff -= minutes * 60
seconds = round(diff, 2)

print(f"Build ran in {hours}h {minutes}m {seconds}s.")