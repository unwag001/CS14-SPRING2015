#!/bin/bash
git config --global user.name unwag001
git config --global user.email unwag001@ucr.edu
git init 
git rm -r --cached *
git remote rm origin
git remote add origin git@github.com:unwag001/CS14-SPRING2015.git
git pull origin master
git add "$1"
git commit -m "update $1"
git push -u origin master
