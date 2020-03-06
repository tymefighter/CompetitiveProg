.PHONY: ts

ts: a b t.py
	@python t.py > test
	@./a < test > out1
	@./b < test > out2
	diff out1 out2