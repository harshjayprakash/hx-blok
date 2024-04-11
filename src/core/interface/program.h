#ifndef BLOQ_PROGRAM_H
#define BLOQ_PROGRAM_H

#include <minwindef.h>

/**
 * \brief Initialises the program.
 */
void bloqInitProgram(void);

/**
 * \brief Saves the arguments used globally throughout the program.
 * 
 * \param instanceHandle handle to the program's instance provided by WinMain.
 * \param showFlag how the application is shown.
 */
void bloqSaveArguments(HINSTANCE instanceHandle, int showFlag);

/**
 * \brief Processes the given arguments given via command line execution.
 */
void bloqProcessArguments(void);

/**
 * \brief Provides a starting point after initialisation.
 */
void bloqStart(void);

/**
 * \brief Retrieves the saved instance handle.
 * 
 * \return HINSTANCE - the instance handle of the program.
 */
HINSTANCE bloqGetInstanceHandle(void);

/**
 * \brief Retrieves the saved show flag.
 * 
 * \return int - the show flag of the program.
 */
int bloqGetShowFlag(void);

/**
 * \brief Cleans up any resources allocated.
 */
void bloqExitProgram(void);

#endif