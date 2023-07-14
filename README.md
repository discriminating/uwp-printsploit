# uwp-printsploit
a printsploit for uwp

it's not auto updating but u can use this sig to find the func addy: `55 8b ec 6a ? 68 ? ? ? ? 64 a1 ? ? ? ? 50 83 ec ? a1 ? ? ? ? 33 c5 89 45 ? 50 8d 45 ? 64 a3 ? ? ? ? 8b 55 ? 8d 45 ? 50 8d 4d ? e8 ? ? ? ? 83 c4 ? 8b 4d`
<br><br>
or u can do a string search for raiseTeleportInitFailedEvent and go to its xref to get it from ida

## how does it work

by rebasing the address and declaring the print function

The decompiled function:<br>
![image](https://github.com/discriminating/uwp-printsploit/assets/99683656/2d5b2676-28b3-4326-873d-c072612803b7)


| a1 (int)     | a2 (const char*) | ... |
| ----------- | ----------- | ----------- |
| 0 | normal text (white)   | extra       |
| 1 | info (blue)           | extra       |
| 2 | warn (yellow)         | extra       |
| 3 | error (red)           | extra       |

example:

| a1 (int)     | a2 (const char*) | ... |
| ----------- | ----------- | ----------- |
| 1 | Address is: 0x%p   | (void*)r_print |

prints:
`(in blue text) Address is: 0xwhatever`

here's it working in mm2:<br>
![image](https://github.com/discriminating/uwp-printsploit/assets/99683656/b4ba1537-9688-4e9c-a8ae-dce7fa6c813e)
