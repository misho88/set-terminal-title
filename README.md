# set-terminal-title
sets the terminal title via ANSI OSC/APC sequence

# purpose

In scripts, you can put in `set-terminal-title "some title"` and, for
compliant terminal emulators, the window title will change, so you can
keep track of what the script is doing.

The behavior regarding `screen` is the same as that of the sample
`bashrc` from BASH 5.1.16; i.e., this should work from within `screen`.
The short version is that this program is somewhat like

```
$ fprintf "\033]0;%s\007" "title"
```

outside screen and somewhat like

```
$ fprintf "\033_%s\033\\" "title"
```

inside `screen`.

# usage

This changes the terminal title for at least three seconds:

```
$ set-terminal-title "the title" && sleep 3
```

Many shells overwrite the title just before and right after a command
is run to reflect its state, so you may not see anything without the
`sleep`.

By default VTE-based terminals don't seem to work this way in the sense
that this is not what `/etc/profile/vte*.sh` defines, and the title
change is somewhat more permanent.

Ultimately, all this program does is send the OSC/APC command.
