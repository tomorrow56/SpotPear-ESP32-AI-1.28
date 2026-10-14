# ハードウェアと設計

対象個体のシルクはSpotPear ESP32-AI-1.28 v1.0。
MAX98357AとNP0557の型番はユーザーの実機情報に基づく。

メーカーの[旧型・脚なしモデル向けガイド](https://spotpear.com/wiki/ESP32-S3-N16R8-AI-DeepSeek-XiaoZhi-XiaGe-Qwen-DouBao-1.28-inch-LCD.html)と
[2025-03-21付の回路図](../hardware/schematics/ESP32S3-1.28inch-AI.pdf)（[メーカー配布元](https://cdn.static.spotpear.com/uploads/picture/learn/ESP32/ESP32-S3-1.28inch-AI/ESP32S3-1.28inch-AI.pdf)）の端子配線を照合した。
ページの回路図リンクの表示名は1.54inchだが、リンク先ファイルは1.28inch。
新型・脚付きやES8311搭載Box版へは適用しない。

| 機能 | 信号 | GPIO |
| --- | --- | --- |
| NP0557 | WS / SCK / DATA | 4 / 5 / 6 |
| MAX98357A | BCLK / LRCLK / DIN | 15 / 16 / 7 |
| GC9A01 | DC / CS / SCLK / MOSI / RESET | 10 / 13 / 14 / 17 / 18 |
| LCD | バックライト | 3 |
| BOOT | 押下でGND | 0 |

マイクL/Rは回路図でGND接続。左右とも初期設定は左スロット。
GPIO3はバックライトのNPNトランジスタを駆動するため正論理。
回路図はESP32-S3R8とW25Q128を示し、実機でも8MB PSRAMと16MB Flashを確認した。

## 流用元

- 主な流用元: Xiaozhi v2.5.0のbread-compact-wifi-lcd。
  WifiBoard、NoAudioCodecSimplex、SpiLcdDisplay、PwmBacklight、BOOT処理を再利用。
- minsi-k08-dual: MAX98357 + INMP441、別クロックのNoAudioCodecSimplexの実例として参照。
- sp-esp32-s3-1.28-box: ES8311、CST816D、LCD GPIOが異なるため使用しない。

共通音声ドライバは改変していない。TXはI2S0/24kHz、RXはI2S1/16kHz。
標準I2S、32bitデータ/スロット、mono左スロット、ESP32がマスター。
共通Read処理は32bit入力を12bit右シフトして16bitに飽和変換する。
電気的な再生参照入力はなく、device AECは追加で有効化していない。
GC9107用やBox固有のLCDコマンドは移植していない。
BOOTのコールバックはApplication::Schedule経由で処理する。

独立したboard名を使用するが、この独自board用の公式OTA配信を保証するものではない。
メーカーガイドは旧型でOTA無効化を案内している。Box版など別機種向けFWを適用しない。
コード上でOTAを強制無効化する変更は含まない。

## 追加の参考回路図

- [BOX版参考回路図 (PDF)](../hardware/schematics/ESP32S3-1.28inch-BOX.pdf)
  — [メーカー配布元](https://cdn.static.spotpear.com/uploads/picture/learn/ESP32/ESP32-S3-LCD-1.28-BOX-THIN/ESP32S3-1.28inch-BOX.pdf)。

BOX版の参考資料として追加したもの。今回の旧型向けGPIO定義は変更していない。

## ケースデータ

[ESP32S3-1.28inch-BOX.step](../hardware/case/ESP32S3-1.28inch-BOX.step)を、
ユーザー提供の原本のまま収録。ケースの寸法・対象個体への適合は未検証。

[ESP32S3-1.28inch-BOX.DWG](../hardware/case/ESP32S3-1.28inch-BOX.DWG)も、ユーザー提供のケース資料として原本のまま収録。
