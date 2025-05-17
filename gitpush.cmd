@echo off
set /p files=Input files to add (e.g. . or *.cpp): 
set /p commit=Input commit message: 

git add "%files%"
git commit -m "%commit%"
git push

echo ✅ Pushed with message: %commit%
pause
