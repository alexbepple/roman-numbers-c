waf := python waf

all: configure build

clean:
	$(waf) clean

configure:
	$(waf) configure

.PHONY: build
build:
	$(waf) build
