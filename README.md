# SpotPear ESP32-AI-1.28 v1.0 — Xiaozhi v2.5.0

**MAX98357Aスピーカーアンプ + NP0557 I2Sマイク**を搭載した旧型・脚なしSpotPear向けの専用board定義とビルド済みファームウェアです。
**実機への書き込み、起動、スピーカー・マイクの動作を確認済みです。**

公式sp-esp32-s3-1.28-box向けFWはES8311/CST816Dと別のGPIOを想定するため、
この個体では音声初期化失敗と再起動の原因になります。
本実装は既存NoAudioCodecSimplexを再利用し、別クロックのI2S音声入出力を構成します。

これは[Xiaozhi本体](https://github.com/78/xiaozhi-esp32)へ適用するboard追加用リポジトリです。
対象タグはv2.5.0、ベースコミットは`ac6deed3d8e75348475364bf40ad953c6cd48054`。

| 項目 | 内容 |
| --- | --- |
| 基板 | SpotPear ESP32-AI-1.28 v1.0、旧型・脚なし |
| MCU / メモリ | ESP32-S3 / Flash 16MB / PSRAM 8MB |
| LCD | GC9A01、240×240 |
| 音声 | MAX98357A + NP0557、送受信別クロック |
| board識別子 | spotpear-esp32-ai-1.28 |
| ビルド環境 | ESP-IDF v6.1、Xtensa GCC 15.2.0 |
| 収録FWの言語 | 中国語 (既定)。日本語は再ビルド時に選択可能 |

## 成果物

- [boardソース](main/boards/spotpear/spotpear-esp32-ai-1.28/)
- [適用用パッチ](patches/spotpear-esp32-ai-1.28-v2.5.0.patch)
- [統合ファームウェア](firmware/v2.5.0/merged-binary.bin) — 初回書き込み、アドレス0x0
- [分割イメージとflash_args](firmware/v2.5.0/)
- [ビルド時設定・依存ロック](build-config/)
- [ハードウェアと流用元](docs/HARDWARE.md)
- [参考回路図：旧型ESP32S3-1.28inch-AI (PDF)](hardware/schematics/ESP32S3-1.28inch-AI.pdf)
- [参考回路図：ESP32S3-1.28inch-BOX (PDF)](hardware/schematics/ESP32S3-1.28inch-BOX.pdf)
- [ケースデータ：ESP32S3-1.28inch-BOX (STEP)](hardware/case/ESP32S3-1.28inch-BOX.step)
- [再ビルド・書き込み手順](docs/BUILD.md)
- [作業・実機検証記録](docs/VALIDATION.md)

チェックサムは[SHA256SUMS](firmware/v2.5.0/SHA256SUMS)。
ファームウェアのビルド成功とスピーカー・マイク動作は確認済みですが、
新型・ES8311搭載Box版への適用や全機能・長時間稼働を検証したものではありません。

## 参考・ライセンス

- [販売元へのリンク（AliExpress）](https://ja.aliexpress.com/item/1005008627679270.html)
- [メーカー旧型ガイド](https://spotpear.com/wiki/ESP32-S3-N16R8-AI-DeepSeek-XiaoZhi-XiaGe-Qwen-DouBao-1.28-inch-LCD.html)
- [メーカーBOX・タッチスクリーン版ガイド](https://spotpear.com/wiki/ESP32-S3-N16R8-AI-DeepSeek-XiaoZhi-XiaGe-Qwen-DouBao-1.28-inch-Round-LCD-BOX-TouchScreen.html)
- [メーカーBOX版参考回路図（配布元PDF）](https://cdn.static.spotpear.com/uploads/picture/learn/ESP32/ESP32-S3-LCD-1.28-BOX-THIN/ESP32S3-1.28inch-BOX.pdf)
- [Xiaozhi v2.5.0](https://github.com/78/xiaozhi-esp32/tree/v2.5.0)
- boardソースは既存実装を基にしており、上流の[MIT License](LICENSE)を保持しています。
- ファームウェアはESP-IDFと各依存コンポーネントも含みます。それぞれのライセンスは上流と[依存一覧](build-config/dependencies.lock)を参照してください。
