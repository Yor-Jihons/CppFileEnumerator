@echo off

if '%1%'=='' (
    echo Pass me some comments.
) ELSE (
    echo The comment:
    echo %1
    git add .
    git commit -m %1%
    git branch -M main
    git push -u origin main
)
