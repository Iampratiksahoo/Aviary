#include "Debug.h"

#include <cstdarg>
#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <Windows.h> // NOT CORE OF WEAVER


#ifdef NDEBUG
static const bool debug_enabled = false;
#else
static const bool debug_enabled = true;
#endif


void Debug::Log(LogType Type, const char* fmt, ...)
{
    if (!debug_enabled) return; 

    set_log_color(Type);
    // Print the actual log message with the format
    std::va_list args;
    va_start(args, fmt);

    for (const char* p = fmt; *p != '\0'; ++p)
    {
        switch (*p)
        {
        case '%':
            switch (*++p) // read format symbol
            {
            case 'd':
                std::cout << va_arg(args, int);
                continue;
            case 'lf':
                std::cout << va_arg(args, double);
                continue;
            case 'f':
                std::cout << va_arg(args, float);
                continue;
            case 's':
                std::cout << va_arg(args, const char*);
                continue;
            case 'c':
                std::cout << static_cast<char>(va_arg(args, int));
                continue;
            case '%':
                std::cout << '%';
                continue;
                /* ...more cases... */
            }
            break; // format error...
        case '\n':
            std::cout << '\n';
            continue;
        case '\t':
            std::cout << '\t';
            continue;
            /* ...more cases... */
        }
        std::cout << *p;
    }

    va_end(args);

    // Add a line at the end of one print message
    std::cout << '\n';

    // Reset the console text color back to white
    reset_log_color();
}

void Debug::Exception(char const* const msg)
{
    throw std::exception(msg); // Throw the exeception
}

/// <summary>
/// True only in debug builds. Also acts as a flag for the Vulkan Validation Layers activation. 
/// </summary>
/// <returns></returns>
bool Debug::LogEnabled()
{
    return debug_enabled;
}


void Debug::set_log_color(LogType Type)
{
    HANDLE m_cli_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    // Set console color as per the type of log
    switch (Type)
    {
    case LogType::Log:
        reset_log_color();
        break;
    case Warning:
        SetConsoleTextAttribute(m_cli_handle, 14);
        break;
    case Error:
        SetConsoleTextAttribute(m_cli_handle, 4);
        break;
    case Success:
        SetConsoleTextAttribute(m_cli_handle, 2);
        break;
    default:
        reset_log_color();
        break;
    }
}

void Debug::reset_log_color()
{
    HANDLE m_cli_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(m_cli_handle, 7);
}
