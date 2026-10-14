# 作業・検証記録

1. 引き継ぎ資料とメーカー旧型ガイド、回路図を調査。
2. Xiaozhi v2.5.0の既存boardを比較し、bread-compact-wifi-lcdとNoAudioCodecSimplexを採用。
3. 専用boardを追加し、ES8311とCST816Dの初期化を使用しない構成にした。
4. ESP-IDF v6.1とS3ツールをSSDに導入し、公式hello_worldのビルドを確認。
5. 専用boardでXiaozhiをビルド、リンク、統合イメージ生成。
6. 16MB Flash全体をバックアップ後、実機へ書き込み。各イメージのハッシュ照合成功。
7. 起動ログで専用board、8MB Octal PSRAM 80MHz、Simplex channels createdを確認。
8. Wi-Fi設定モードへ移行し、観測したログにES8311初期化エラー・abort・panicなし。
9. 2026-10-15、ユーザーよりスピーカーとマイクの実機動作成功の報告あり。

## ビルド結果

- Xiaozhi v2.5.0 / ESP-IDF v6.1 / ESP32-S3。
- 既存ホストテスト81件成功。clang-formatチェックとgit diff --check成功。
- board登録をbuild.pyの一覧で確認、専用board .ccのコンパイルを確認。
- xiaozhi.bin: 2,673,200 bytes (0x28ca30)。アプリ領域の空き35%。
- merged-binary.bin: 9,651,265 bytes。
- esptool image-infoによるイメージチェックサム・検証ハッシュは正常。
- コンパイラのwarning/error行なし。初期構成時に他boardの曖昧性警告とKconfig通知はあった。
- ビルド時刻: 2026-10-14 21:37 JST、完了21:38 JST。結果確認は2026-10-15。

初回監視にはUSB_UART_CHIP_RESETによる再起動が含まれる。
無期限の連続稼働試験を行ったわけではない。
LCDの向き・色の詳細、長時間会話、AEC、バッテリー・タッチ等の試験は未記録。
生のUARTログやFlashバックアップは実機識別情報・周辺ネットワーク情報を含むため非公開。
公開する設定はビルド時のsdkconfigとdependencies.lockのみ。
