# Mocking with Fakes

Fakes allow you to intercept function calls and redirect them to a different function known as the "fake" function.
For the fake function to work correctly, its signature must match the original function precisely; otherwise, the behavior is undefined.
The fake function can include custom logic for parameter validation, call through to the original function, and return its own value as needed.
