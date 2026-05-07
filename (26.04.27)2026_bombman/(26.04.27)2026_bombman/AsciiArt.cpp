#include "AsciiArt.h"

void InitAscii(AsciiObjs& objs)
{
    objs.plane =
    {
       "        _        ",
       "      -= \`\     ",
       "  | \ ____\_\__  ",
       "-= \c`""""""" "`)",
       "   `~~~~~/ /~~`  ",
       "     -= = / /    ",
       "       '-'       ",
    };
    objs.cloud =
    {
     "      _  _       ",
     "    ( `   )_     ",
     "   (    )    `)  ",
     " (_   (_ .  _) _)",
    };
}

void UpdateAscii(AsciiObjs& objs)
{
}

void RenderAscii(const AsciiObjs& objs)
{
}
