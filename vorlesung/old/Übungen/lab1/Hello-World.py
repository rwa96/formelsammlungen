#!/usr/bin/env python


class HelloWorld:

	def __init__(self, msg: str):
		self.msg = msg

	def call(self):
		for count in range(10):
			print(self.msg)


def main() -> int:
	HelloWorld("Hello World").call()
	return 0


if __name__ == '__main__':
	exit(main())
