
NAME=thesis
TEXSRCS=$(wildcard tex/*.tex)

.PHONY: my_all
my_all: pdf

include /usr/local/share/latex-mk/latex.gmk

