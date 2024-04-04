#!/bin/sh

id -Gn $FT_USER | tr ' ' ',' | head -c -1
