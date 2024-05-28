##
## EPITECH PROJECT, 2024
## Zappy GUI
## File description:
## Makefile
##


SRC		=   src/Main.cpp														\
			src/Components/Background2D/ComponentBackground2D.cpp				\
			src/Components/Button/ComponentButton.cpp							\
			src/Components/SliderVolume/SliderVolume.cpp							\
			src/Components/Circle/ComponentCircle.cpp							\
			src/Components/Image/ComponentImage.cpp								\
			src/Components/RoundedRectangle/ComponentRoundedRectangle.cpp		\
			src/Components/Skybox/ComponentSkybox.cpp							\
			src/Components/Text/ComponentText.cpp								\
			src/Parsing/Parsing.cpp												\
			src/Parsing/ParsingError.cpp										\
			src/Parsing/ParsingHelp.cpp											\
			src/Raylib/ColorManager/ColorManager.cpp							\
			src/Raylib/Render/Render.cpp										\
			src/Raylib/View/View.cpp											\
			src/SceneManager/SceneManager.cpp									\
			src/Scenes/AScene/AScene.cpp										\
			src/Scenes/GameScene/GameScene.cpp									\
			src/Scenes/MenuScene/MenuScene.cpp									\
			src/Scenes/OptionScene/OptionScene.cpp								\
			src/Scenes/OptionScene/SoundOption/SoundOptionScene.cpp				\
			src/Scenes/OptionScene/ResolutionOption/ResolutionOptionScene.cpp	\
			src/Utils/Utils.cpp													\

OBJ 	= 	$(patsubst src/%.cpp,compiled_object/%.o,$(SRC))

RESET		= "\033[0m"
BLUE		= "\033[34m"
BOLD		= "\033[1m"
FBLUE		= "\033[94m"
FGREEN		= "\033[92m"
FRED		= "\033[91m"
FYELLOW		= "\033[93m"
GREEN		= "\033[32m"
PURPLE		= "\033[35m"
RED			= "\033[31m"
YELLOW		= "\033[33m"

BIN	=	"zappy_gui"

FLAGS	=	-Wall 				\
			-Wextra				\
			-Wfloat-equal 		\
			-Wundef 			\
			-Wcast-align		\
			-Wshadow			\
			-Wlogical-op		\
			-Wredundant-decls	\
			-std=c++20			\
			-O2

INCLUDES	=	-I./libs/includes							\
				-I./includes								\
				-I./src										\
				-I./src/Components/Background2D				\
				-I./src/Components/Button					\
				-I./src/Components/SliderVolume				\
				-I./src/Components/Circle					\
				-I./src/Components/Image					\
				-I./src/Components/RoundedRectangle			\
				-I./src/Components/Skybox					\
				-I./src/Components/Text						\
				-I./src/Parsing								\
				-I./src/Raylib/ColorManager					\
				-I./src/Raylib/Render						\
				-I./src/Raylib/View							\
				-I./src/SceneManager						\
				-I./src/Scenes/IScene						\
				-I./src/Scenes/AScene						\
				-I./src/Scenes/GameScene					\
				-I./src/Scenes/MenuScene					\
				-I./src/Scenes/OptionScene					\
				-I./src/Scenes/OptionScene/SoundOption      \
				-I./src/Scenes/OptionScene/ResolutionOption \
				-I./src/Utils								\

LIBS	=	-L./libs	\
			-lraylib 	\
			-lGL 		\
			-lm			\
			-lpthread	\
			-ldl		\
			-lrt		\
			-lX11

COMP	=	g++

all:	$(BIN)

$(BIN):	makeLibs $(OBJ)
	@echo $(BOLD)$(GREEN)"Objects Done\n\n"$(RESET)
	@echo $(BOLD)$(PURPLE)"Compiling $(BIN)..."$(RESET)
	@$(COMP) -o $(BIN) $(OBJ) $(FLAGS) $(INCLUDES) $(LIBS)
	@make ascii

makeLibs:
	@if [ -n "$$(ls -A libs | grep -vE '(^includes$$|^Makefile$$)')" ]; then \
		echo $(BOLD)$(PURPLE)"Making Libs..."$(RESET); \
		make -C libs; \
		echo $(BOLD)$(GREEN)"Libs Done\n\n"$(RESET); \
	fi
	@echo $(BOLD)$(PURPLE)"Compiling objects..."$(RESET)

clean:
	@if [ -n "$$(ls -A libs | grep -vE '(^includes$$|^Makefile$$)')" ]; then \
		make -C libs clean; \
	fi
	@rm -rf compiled_object
	@rm -rf vgcore*

fclean: clean
	@if [ -n "$$(ls -A libs | grep -vE '(^includes$$|^Makefile$$)')" ]; then \
		make -C libs fclean; \
	fi
	@rm -rf $(BIN)

re: fclean all

compiled_object/%.o: src/%.cpp
	@mkdir -p $(@D)
	@$(COMP) $(FLAGS) $(INCLUDES) $(LIBS) -g3 -c -o $@ $<
	@echo $(GREEN)">> compiling $<"$(RESET)


ascii:
	@echo $(BOLD)$(PURPLE)
	@echo "\n\n\t(„• ֊ •„)❤"
	@echo "\t┏━U━━━U━━━━━━━━━━━━━━━━━┓"
	@echo "\t  $(BIN) ready to be used"
	@echo "\t┗━━━━━━━━━━━━━━━━━━━━━━━┛\n\n"
	@echo $(RESET)
