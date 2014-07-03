#!/usr/bin/env python

import os, sys, re, math
import json
from subprocess import Popen, PIPE

cmdline = sys.argv[1:]

if len(cmdline) > 1:
    print "Too much args. Exiting..."
    sys.exit(1)

if len(cmdline) == 0:
	print "Usage MPSoCBenchWithMcPAT <input-file>.json"
	sys.exit(1)

if not os.path.isfile(cmdline[0]):
    print "File does not exists. Exiting..."
    sys.exit(1)

data = open(cmdline[0])
data = data.read()
data = data.split('\n')
pattern = "void ac_behavior\(\s(\w+)\s\)$"
prog = re.compile(pattern)
instructions = []
for line in data:
	match = prog.findall(line)
	if match:
		if match[0] != "instruction" and match[0] != "begin" and match[0] != "end":
			instructions.append(match[0])

pattern = "CounterInstructionType::add\(\"inst\"\);"
prog = re.compile(pattern)
i = 0
j = 0
for line in data:
	match = prog.findall(line)
	if match:
		data[i] = "CounterInstructionType::add(\""+instructions[j]+"\");};";
		j += 1
	i += 1

f = open(cmdline[0], 'w')

for line in data:
	f.write(line+'\n')
f.close()