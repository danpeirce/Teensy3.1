#include "command.h"

static enum commands_type start( char rx_char );
static enum commands_type start1( char rx_char );
static enum commands_type start2( char rx_char );
static enum commands_type led1( char rx_char );
static enum commands_type led2( char rx_char );
static enum commands_type led3( char rx_char );
static enum commands_type led4( char rx_char );
static enum commands_type led5( char rx_char );
// static enum commands_type run( char rx_char );


// function pointer
static enum commands_type (*state)( char rx_char ) = start;

enum commands_type command( char rx_char )
{
    enum commands_type the_command;
    the_command = state( rx_char );
    return the_command;
}

static enum commands_type start( char rx_char )
{
    enum commands_type the_command = nullc;
    if (rx_char)
    {
        switch (rx_char)
        {
            case 's':
            case 'S':
                state = start1;
                break;
            case '\n':
            case '\r':
            case ' ':
                break;
            case 'l':
            case 'L':
                state = led1;
                break;
            default:
                the_command = resetc;
                break;
        } 
    }
	
    return the_command ;
}

static enum commands_type start1( char rx_char )
{
    enum commands_type the_command = nullc;
    if (rx_char)
    {
        switch (rx_char)
        {
            case 't':
            case 'T':
                state = start2;
                break;
            case '\n':
            case '\r':
            case ' ':
                break;
            default:
                the_command = resetc;
                break;
        } 
    }
	
    return the_command ;
}

static enum commands_type start2( char rx_char )
{
    enum commands_type the_command = nullc;
    if (rx_char)
    {
        switch (rx_char)
        {
            case 'a':
            case 'A':
                state = start;
                the_command = startc;
                break;
            case '\n':
            case '\r':
            case ' ':
                break;
            default:
                the_command = resetc;
                break;
        } 
    }
	
    return the_command ;
}

static enum commands_type led1( char rx_char )
{
    enum commands_type the_command = nullc;
    if (rx_char)
    {
        switch (rx_char)
        {

            case '\n':
            case '\r':
            case ' ':
                break;
            case 'e':
            case 'E':
                state = led2;
                break;
            default:
                the_command = resetc;
                break;
        } 
    }
	
    return the_command ;
}

static enum commands_type led2( char rx_char )
{
    enum commands_type the_command = nullc;
    if (rx_char)
    {
        switch (rx_char)
        {

            case '\n':
            case '\r':
            case ' ':
                break;
            case 'd':
            case 'D':
                state = led3;
                break;
            default:
                the_command = resetc;
                break;
        } 
    }
	
    return the_command ;
}

static enum commands_type led3( char rx_char )
{
    enum commands_type the_command = nullc;
    if (rx_char)
    {
        switch (rx_char)
        {

            case '\n':
            case '\r':
            case ' ':
                break;
            case 'o':
            case 'O':
                state = led4;
                break;
            default:
                the_command = resetc;
                break;
        } 
    }
	
    return the_command ;
}

static enum commands_type led4( char rx_char )
{
    enum commands_type the_command = nullc;
    if (rx_char)
    {
        switch (rx_char)
        {

            case '\n':
            case '\r':
            case ' ':
                break;
            case 'n':
            case 'N':
                state = start;
                the_command = on13c;
                break;
            case 'f':
            case 'F':
                state = led5;
              //  the_command = on13c;
                break;
            default:
                the_command = resetc;
                break;
        } 
    }
	
    return the_command ;
    
}

static enum commands_type led5( char rx_char )
{
    enum commands_type the_command = nullc;
    if (rx_char)
    {
        switch (rx_char)
        {

            case '\n':
            case '\r':
            case ' ':
                break;
            case 'f':
            case 'F':
                state = start;
                the_command = off13c;
                break;
            default:
                the_command = resetc;
                break;
        } 
    }
	
    return the_command ;
    
}
