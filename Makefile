FLASH_ROOT = ~/repos/qmk_firmware/keyboards/planck/keymaps

ez:
	bash ./flash.sh planck_ez $(FLASH_ROOT)/renzmann_ez

grid:
	bash ./flash.sh planck_grid $(FLASH_ROOT)/renzmann_grid

mit:
	bash ./flash.sh planck_mit $(FLASH_ROOT)/renzmann_mit
