# File Driven Testing

This example demonstrates invoking a test case for each file in the "input/" directory.
The data within these files is interpreted as input data for the test.
The files in the "output/" directory contain the expected results.

It is important to note that the number of files in both directories must match.
Real-world test utilities must be robust enough to catch this and report an error.
If you have multiple suites that are file-driven, then consider moving the logic to parse them into a common place for reusability.
