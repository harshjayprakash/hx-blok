#include "program.h"

static program s_program_instance;
void program_init(
    HINSTANCE _instance_handle, 
    HINSTANCE _previous_instance_handle, 
    LPSTR _command_line_arguments, 
    int _show_flag)
{
    s_program_instance.instance_handle = _instance_handle;
    s_program_instance.previous_instance_handle = _previous_instance_handle;
    s_program_instance.command_line_arguments = _command_line_arguments;
    s_program_instance.show_flag = _show_flag;

}

program *program_instance_get(void)
{
    return &s_program_instance;
}

void program_free(void)
{

}