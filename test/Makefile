# auxiliary variables
PROJECT_DIR=/home/satan/marcel/seminar2
SRC_DIR=$(PROJECT_DIR)/src
TEST_DIR=$(PROJECT_DIR)/test

# variables defined as described in the MakeileWorker.mk
CPPUTEST_HOME=/home/satan/Downloads/cpputest
INCLUDE_DIRS=$(SRC_DIR)/calc $(SRC_DIR)/stack $(CPPUTEST_HOME)/include
SRC_DIRS=$(SRC_DIR)/calc $(SRC_DIR)/stack
TEST_SRC_DIRS = $(TEST_DIR)
TEST_TARGET=out
CPPUTEST_USE_GCOV=Y

# run MakefileWorker.mk with the variables defined here
include $(CPPUTEST_HOME)/build/MakefileWorker.mk

# removes some compilation flags
CPPUTEST_WARNINGFLAGS:=$(filter-out -Werror,$(CPPUTEST_WARNINGFLAGS)) 

# adds some other warnings
CPPUTEST_WARNINGFLAGS+=-Wunused-result