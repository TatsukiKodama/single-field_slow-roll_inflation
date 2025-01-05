# コンパイラとフラグの設定
CC = clang
CFLAGS = -Wall -Wextra -std=c99

# ソースディレクトリとオブジェクトディレクトリ
SRCDIR = src
UTILSDIR = $(SRCDIR)/utils
OBJDIR = obj
SRC_OBJDIR = $(OBJDIR)/src
UTILS_OBJDIR = $(OBJDIR)/utils

# ソースファイルとオブジェクトファイルの設定
SRC_SRCS = $(wildcard $(SRCDIR)/*.c)
UTILS_SRCS = $(wildcard $(UTILSDIR)/*.c)
SRC_OBJS = $(SRC_SRCS:$(SRCDIR)/%.c=$(SRC_OBJDIR)/%.o)
UTILS_OBJS = $(UTILS_SRCS:$(UTILSDIR)/%.c=$(UTILS_OBJDIR)/%.o)
OBJS = $(SRC_OBJS) $(UTILS_OBJS)

# 出力ファイル名
TARGET = main

# ========================================================== #

# すべてのターゲット
all: $(TARGET)

# 実行ファイルの生成
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# src 内のオブジェクトファイル生成
$(SRC_OBJDIR)/%.o: $(SRCDIR)/%.c | $(SRC_OBJDIR)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# utils 内のオブジェクトファイル生成
$(UTILS_OBJDIR)/%.o: $(UTILSDIR)/%.c | $(UTILS_OBJDIR)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# 必要なディレクトリの作成
$(SRC_OBJDIR):
	mkdir -p $(SRC_OBJDIR)

$(UTILS_OBJDIR):
	mkdir -p $(UTILS_OBJDIR)

# クリーンアップ
clean:
	rm -rf $(OBJDIR) $(TARGET)
