@echo off

:: Add all changes
git add .

:: Ask for a commit message
set /p commitMsg=Enter commit message:

:: Commit with the provided message
git commit -m "%commitMsg%"

:: Push to the repository
git push

