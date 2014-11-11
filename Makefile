
NAME=thesis
TEXSRCS=$(wildcard tex/*.tex)
PNGS=$(wildcard img/*.png)
EPSS=$(patsubst %.png,%.eps,$(PNGS))

img/%.eps: img/%.png
	convert -compress Lossless $< $@

.PHONY: my_all
my_all: $(EPSS) pdf

include /usr/local/share/latex-mk/latex.gmk

