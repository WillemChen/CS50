// Helper functions for music

#include <cs50.h>
#include <math.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO
    int deno = atoi(&fraction[2]);
    int numer = atoi(&fraction[0]);
    if (deno < 8)
    {
        while (deno != 8)
        {
            deno *= 2;
            numer *= 2;
        }
    }
    return numer;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    double counter = 0;
    switch (note[0])
    {
        case 'C':
            counter -= 9;
            break;
        case 'D':
            counter -= 7;
            break;
        case 'E':
            counter -= 5;
            break;
        case 'F':
            counter -= 4;
            break;
        case 'G':
            counter -= 2;
            break;
        case 'A':
            break;
        case 'B':
            counter += 2;
            break;
    }
    if (note[1] == 'b' || note[1] == '#')
    {
        counter = counter + (note[2] - 52) * 12;
        if (note[1] == 'b')
        {
            counter -= 2;
        }
        counter++;
    }
    else
    {
        counter = counter + (note[1] - 52) * 12;
    }
    int hz = round(pow(2, counter / 12) * 440);
    return hz;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO

    if (s[0] == '\0')
    {
        return 1;
    }
    return 0;
}
