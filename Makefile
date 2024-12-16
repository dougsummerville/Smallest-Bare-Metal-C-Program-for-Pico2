ledon.uf2: ledon.elf
	python3 tools/elf2uf2.py $<
ledon.elf: ledon.c
	arm-none-eabi-gcc -ffreestanding -nostartfiles -mcpu=cortex-m33 -T pico2.ld $< -o $@
clean:
	rm ledon.uf2 ledon.elf
