#!/usr/bin/env python


with open("/etc/passwd", "r") as passwd_file:
	for line in passwd_file.readlines():
		fields = line.strip("\n").split(":")
		print(f"{fields[0]} {fields[2]}")
