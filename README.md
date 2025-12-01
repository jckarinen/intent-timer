# Intent Timer

A simple application that will lock your computer after a specified time, encouraging you to get up and take a break.

I decided to create this application because I have a bad habit of sitting too long at the computer, especially when I'm focused on building an application. Programming is fun, so it's hard to know when to quit. Hours can disappear instantly, and often you might forget to move around or even eat.

To start, I wanted to create the simplest possible implementation of the program that would still be useful to me. So I wrote a really crappy version with my (currently very limited) working knowledge of C.

--- 

Some stuff to keep in mind:

- Currently the program only works on MacOS
- The way the program sends notifications (via AppleScript) leaves a lot to be desired. You won't even be able to see the notifications unless you first follow these steps:
    1. Open Script Editor
    2. Paste in this script and click the play button: `display notification "hey this is a notification" with title "my notification"`
    3. Go to Settings > Notifications > scroll down to Script Editor and enable notifications

Yeah, pretty weird, isn't it?

Eventually, I'll create a cross-platform GUI for the application so that it can be used by normal humans. For now, it's serving its purpose on my system!
