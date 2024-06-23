import sys
import os
import random

for i in range(1, 61):
    num_str = str(i)
    while len(num_str) < 2:
        num_str = "0" + num_str
    
    pcall = f"sol <jumps.{num_str}.in >jumps.{num_str}.sol"
    os.system(pcall)
    