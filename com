#!/bin/bash
git add .
echo "enter message to commit:"
read myCommit
git commit -m "$myCommit"
