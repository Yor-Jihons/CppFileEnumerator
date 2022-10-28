#----------------------------------------------------------#
# ディレクトリパス定義

## srcディレクトリ
SRCDIRPATH=.\src

## 生成する場所の指定
BINDIRPATH=.\bin

#----------------------------------------------------------#
# 生成する対象の指定

## 対象のプロジェクト
TARGET=$(BINDIRPATH)\libobjectivefileenum.a

## 対象リスト
all: $(TARGET)

#----------------------------------------------------------#
# コンパイラ関連の定義

## コンパイラの指定
CCX=g++
AR=ar

## 最適化について
OPTIMIZE=-o2

## C++のバージョン指定
CPP_VERSION=-std=c++11

## インクルードの指定 ( -Iでやるやつ )
ICOMMAND=

## リンカのフラグ
LDFLAG=-O0

## コンパイラフラグ
CFLAG=$(OPTIMIZE) $(CPP_VERSION) $(ICOMMAND)

## リンクする独自ソースコード
OBJECTFILES=$(SRCDIRPATH)\FileEnumerator.o $(SRCDIRPATH)\EnumResult.o

#----------------------------------------------------------#
# コンパイル

## 対象プロジェクトのコンパイル
$(TARGET): $(OBJECTFILES)
	$(AR) r $@ $(OBJECTFILES)

## 必要なオブジェクトファイルのコンパイル
$(SRCDIRPATH)\FileEnumerator.o: $(SRCDIRPATH)\FileEnumerator.cpp
	$(CCX) $(CPP_VERSION) -o $@ -c $<
$(SRCDIRPATH)\EnumResult.o: $(SRCDIRPATH)\EnumResult.cpp
	$(CCX) $(CPP_VERSION) -o $@ -c $<

#----------------------------------------------------------#
# 後始末

## 削除系
clean:
	@rm -rf $(LINKAGEFILES) $(TARGET)
