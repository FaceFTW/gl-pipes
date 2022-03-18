/**
 * @file state_flexy.cpp
 * @author Alex "FaceFTW" Westerman
 * @brief 
 * @version 0.1
 * @date 2022-03-15
 * 
 * @copyright Copyright (c) 2022. Work is based on original work from Microsoft Corp (c) 1994
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/timeb.h>
#include <time.h>
//TODO Remove windows bindings
#include <windows.h>


#include "include/pipe_main.h"
#include "fstate.h"
#include "nstate.h"
#include "npipe.h"
#include "fpipe.h"

/******************************Public*Routine******************************\
* FLEX_STATE constructor
*
\**************************************************************************/

FLEX_STATE::FLEX_STATE( STATE *pState )
{
    bTexture = pState->bTexture;
    Reset();
}

/**************************************************************************\
* Reset
*
* Reset a frame of normal pipes.
*
\**************************************************************************/

void 
FLEX_STATE::Reset( )
{
    // Choose a random scheme for each frame

    if( ss_iRand(2) )  // 50/50
        scheme = SC_EXTRUDED_XC;
    else
        scheme = SC_TURNOMANIA;
}

/**************************************************************************\
* OKToUseChase
*
* Determines if we can use chase mode for flex pipes
*
\**************************************************************************/

BOOL
FLEX_STATE::OKToUseChase( )
{
    return scheme != SC_TURNOMANIA;
}

/**************************************************************************\
* NewPipe
*
* Create a new pipe, based on current drawing scheme
*
\**************************************************************************/

PIPE*
FLEX_STATE::NewPipe( STATE *pState )
{
    if( scheme == SC_TURNOMANIA )
        return new TURNING_FLEX_PIPE( pState );
    else
        return new REGULAR_FLEX_PIPE( pState );
}

/**************************************************************************\
* GetMaxPipesPerFrame
*
\**************************************************************************/

int
FLEX_STATE::GetMaxPipesPerFrame( )
{
    if( scheme == SC_TURNOMANIA ) {
        return TURNOMANIA_PIPE_COUNT;
        if( bTexture )
            return TURNOMANIA_PIPE_COUNT / 2;
    } else {
        return bTexture ? NORMAL_TEX_PIPE_COUNT : NORMAL_PIPE_COUNT;
    }
}
