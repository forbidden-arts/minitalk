# minitalk
![dpalmer's 42 stats](https://badge42.vercel.app/api/v2/cli5pb141011308mh1fmi5qrq/stats?cursusId=21&coalitionId=271)

![Achievement Unlocked!](./assets/minitalkm.png)

![dpalmer's 42 minitalk Score](https://badge42.vercel.app/api/v2/cli5pb141011308mh1fmi5qrq/project/2909191)

## 🪧 Overview
Ah yes, the ever-useful printf: quick debugger of code, handler of an unspecified number of arguments, and **pain in my butt.**

Well, at least at first. The purpose of this project is to get familiar with variadic arguments. For those of you who are _not_ nerds, that's a nerdy way of saying that you can give this function a lot of different stuff, and it should be able to handle all (or at least most) of the crazy things you ask it to do.

After staring at the requirements for a few days, I decided to jump in head first, which later taught me a valuable lesson: not exhaustively considering all the corner cases means a lot of refactoring. This was the first project that I did not max-out the bonuses, as when it came time to add them, I realized that it would require a 💪Herculean💪 rewrite that would toss 75% of what I had written in the trash.

Lesson learned.

Little known fact: the 'f' stands for "Ah, 🤬, I should have thought of that" and also for "format", according to the man pages.


This has been integrated into [libft](https://github.com/forbidden-arts/libft).

## 📷 Preview
Want to send a message to the user? Want to show memory addresses? Want to print numbers? Maybe letters, but as numbers? Yeah, this will do that. The integrated version in [libft](https://github.com/forbidden-arts/libft) is probably more up to date. This is just here for posterity (or lack thereof).

To make myself feel better, I added some color to the makefile. Pretty fancy, right?

![Screenshot](./assets/minitalk_gif.gif)

## 💻 Compilation
To compile:
```make```
Remove the object files:
```make clean```
Remove everything:
```make fclean```

### 📝 License
Distributed under the MIT License. See [LICENSE](LICENSE) for more information.
