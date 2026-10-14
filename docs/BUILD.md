# 再ビルドと書き込み

## 必要環境

- ESP-IDF >=6.0.1、今回の検証環境はv6.1/macOS arm64。
- ESP32-S3用ツールチェーン。検証時はXtensa GCC 15.2.0、Python 3.14.6。
- Xiaozhi v2.5.0、コミットac6deed3d8e75348475364bf40ad953c6cd48054。

メーカー旧ソース向けのIDF 5.3手順は今回のv2.5.0ソースに適用しない。
ESP-IDF導入例:

```sh
git clone --branch v6.1 --recursive https://github.com/espressif/esp-idf.git esp-idf-v6.1
cd esp-idf-v6.1
./install.sh esp32s3
. ./export.sh
idf.py --version
```

## パッチ適用とビルド

```sh
git clone https://github.com/tomorrow56/SpotPear-ESP32-AI-1.28.git
git clone --branch v2.5.0 --depth 1 https://github.com/78/xiaozhi-esp32.git xiaozhi-esp32-v2.5.0
cd xiaozhi-esp32-v2.5.0
git apply --check ../SpotPear-ESP32-AI-1.28/patches/spotpear-esp32-ai-1.28-v2.5.0.patch
git apply ../SpotPear-ESP32-AI-1.28/patches/spotpear-esp32-ai-1.28-v2.5.0.patch
python scripts/build.py spotpear/spotpear-esp32-ai-1.28 --name spotpear-esp32-ai-1.28
```

このパッチにはboardファイルの追加、main/CMakeLists.txt、main/Kconfig.projbuildへの登録が含まれる。
パッチ適用後にboardディレクトリを別途コピーする必要はない。
CMakeはboardディレクトリ内の.ccを自動収集する。GC9A01は既存の依存を使用。

中国語が既定。日本語版を作る場合はbuild.pyコマンドに `--language ja-JP` を追加する。
収録済みのファームウェアは中国語版。

有効な設定:

```text
CONFIG_BOARD_TYPE_SPOTPEAR_ESP32_AI_1_28=y
CONFIG_ESPTOOLPY_FLASHSIZE_16MB=y
CONFIG_PARTITION_TABLE_CUSTOM_FILENAME="partitions/v2/16m.csv"
CONFIG_SPIRAM=y
CONFIG_SPIRAM_MODE_OCT=y
CONFIG_SPIRAM_SPEED_80M=y
```

QIOが選択されていてもIDF生成のflash_argsとブートイメージヘッダはDIO。
実機起動ログではアプリ起動時のFlash QIOを確認した。書き込み引数は生成値に従う。

## 書き込み

先に対象シリアルポートを確認する。既存FWや設定を保存したい場合は16MB Flashをバックアップする。
今回のバックアップは実機固有情報を含むため本リポジトリに収録していない。

ビルドしたソースから:

```sh
idf.py -p PORT flash monitor
```

収録バイナリを使う場合は本リポジトリのルートから:

```sh
cd firmware/v2.5.0
python -m esptool --chip esp32s3 -p PORT write-flash @flash_args
```

統合イメージを使う場合は同じディレクトリで:

```sh
python -m esptool --chip esp32s3 -p PORT write-flash 0x0 merged-binary.bin
```

統合版の開始アドレスは0x0。xiaozhi.bin単体は0x20000。
初回はbootloader・partition・OTA初期データ・assetsも必要。
書き込みは既存のOTAデータやassetsを変更する。flash全消去は今回行っていない。

起動後は画面に表示されるXiaozhi-xxxxへ接続し、http://192.168.4.1 でWi-Fiを設定する。

## macOS外部ディスクの注意

最初のビルドでは外部ディスク上の._*.cメタデータをLVGLがソースとして拾い失敗した。
._*を除外して別のSSDへソースと依存をコピーし、新規buildディレクトリで成功した。
コピー後に古いbuildディレクトリを再利用しないこと。
