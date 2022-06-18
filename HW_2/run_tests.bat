@ECHO OFF
SET /p Project="Project name [project.uproject]: "
SET /p SetOfTest="Set of tests [PrettyName]: "
SET /p LogFile="Log file name [report.txt]: "

IF NOT DEFINED Project (
    ECHO [91m [Project name] is not defined! [0m 
    PAUSE
    EXIT 1)
IF NOT DEFINED SetOfTest (
    ECHO [91m [Set of tests] is not defined! [0m 
    PAUSE
    EXIT 1)
IF NOT DEFINED LogFile (
    ECHO [91m [Log file name] is not defined! [0m
    PAUSE
    EXIT 1)

ECHO  Testing started

"C:\Program Files\Epic Games\UE_4.27\Engine\Binaries\Win64\UE4Editor.exe" %Project% ^
              -ExecCmds="Automation RunTests %SetOfTest%" ^
              -unattended ^
              -nopause ^
              -testexit="Automation Test Queue Empty" ^
              -log=%LogFile% ^
              -log ^
              -game

ECHO [92m Testing Done[0m

PAUSE
