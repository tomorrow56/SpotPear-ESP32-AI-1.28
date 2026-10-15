# ファームウェアのソース一式

`xiaozhi-esp32-v2.5.0/` に、実機動作確認済みFWのビルドに使用したソースを収録しています。
上流v2.5.0 (`ac6deed3d8e75348475364bf40ad953c6cd48054`) の追跡対象全ファイルへ、
SpotPear専用board、CMake/Kconfig登録、ビルド時のdependencies.lockを加えたスナップショットです。
boardのREADMEにはビルド後の実機確認結果を反映しています。

## ビルド

ESP-IDF v6.1環境を有効化したうえで:

```sh
cd firmware-source/xiaozhi-esp32-v2.5.0
python scripts/build.py spotpear/spotpear-esp32-ai-1.28 --name spotpear-esp32-ai-1.28
```

パッチは適用済みの状態なので、追加で適用しません。
依存コンポーネントはmanifestとdependencies.lockに基づいて初回構成時に取得します。
ESP-IDF本体、コンパイラ、managed_components、build、生成済みsdkconfigは収録対象外です。
ビルド時の設定控えはルートのbuild-config/にあります。

出典は[PROVENANCE.json](PROVENANCE.json)、各ファイルのチェックサムは[SHA256SUMS](SHA256SUMS)。
上流のLICENSEとライセンス表記を保持しています。
詳細手順は[docs/BUILD.md](../docs/BUILD.md)を参照してください。
