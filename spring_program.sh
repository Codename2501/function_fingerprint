#!/bin/bash

# Cプログラムをコンパイル
gcc spring_program.c -o spring_program -lm

# データファイルを初期化 (空ファイルを作成)
rm -f spring_program.dat
touch spring_program.dat

# Gnuplotをバックグラウンドで起動し、プロセスIDを保存
# -p (persist) オプションは手動でkillするため不要
gnuplot spring_program.gp &
GNUPLOT_PID=$!

echo "Gnuplot (PID: $GNUPLOT_PID) を起動し、データ生成を開始します..."

# Cプログラムを実行し、出力をデータファイルにリダイレクト
# この処理が完了するまでスクリプトはここで待機する
./spring_program > spring_program.dat

# Cプログラムが終了した後の処理
echo "データ生成が完了しました。"
echo "グラフを確認後、このターミナルでEnterキーを押すとGnuplotを終了します。"

# ユーザーがEnterキーを押すのを待つ
read

# バックグラウンドのGnuplotを終了させる
kill $GNUPLOT_PID

echo "処理が完了しました。✅"
