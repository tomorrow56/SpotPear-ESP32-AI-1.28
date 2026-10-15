# SpotPear ESP32-AI-1.28 v1.0

旧型・脚なし、MAX98357A + NP0557の個体向け。Xiaozhi v2.5.0用。

NoAudioCodecSimplexでスピーカーI2S0とマイクI2S1に別々のBCLK/WSを供給する。
LCDはGC9A01の標準ドライバ、240x240、BGR、Xミラー、色反転あり。
GPIOはconfig.h、調査根拠はリポジトリのdocs/HARDWARE.mdを参照。

実機への書き込みと起動、スピーカー・マイクの動作を2026-10-15に確認済み。
LCDの色・向き、長時間の連続会話、AEC等の詳細試験は未記録。

ES8311/CST816Dを使うsp-esp32-s3-1.28-boxとは別のboard識別子を持つ。
タッチ、バッテリーADC、カメラ、WS2812Bはこの実装では有効化しない。

config.jsonは16MB FlashとOctal PSRAM 80MHzのS3既定値を継承する。
再ビルドと登録方法はルートREADME.mdとdocs/BUILD.mdを参照。
