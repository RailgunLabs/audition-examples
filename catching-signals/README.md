# Catching Signals

Test cases can assert that a specific POSIX signal is raised.
If the test does **not** raise the expected POSIX signal or if it raises with the wrong signal, then the test fails.
