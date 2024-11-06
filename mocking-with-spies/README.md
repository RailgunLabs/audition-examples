# Mocking with Spies

A **spy** is a technique used to monitor the behavior of a function, particularly its input arguments and return values, without altering its behavior.
Audition does not have a built-in spy concept, however, you can implement a spy yourself by redirecting function calls to a fake function that records the arguments, calls the original function, and returns the original functions return value.
In this way, the fake is used to transparently intercept calls to the original function.
