/*!
 * \file MainWindow.h
 * \author masc4ii
 * \copyright 2017
 * \brief The main window
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QTimerEvent>
#include <QResizeEvent>
#include <QFileOpenEvent>
#include <QThreadPool>
#include <QProcess>
#include <QVector>
#include <QGraphicsPixmapItem>
#include <QCloseEvent>
#include "../../src/mlv_include.h"
#include "InfoDialog.h"
#include "StatusDialog.h"
#include "Histogram.h"
#include "WaveFormMonitor.h"
#include "AudioWave.h"
#include "ReceiptSettings.h"
#include "AudioPlayback.h"
#include "GraphicsPickerScene.h"
#include "RenderFrameThread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(int &argc, char **argv, QWidget *parent = 0);
    ~MainWindow();

protected:
    void timerEvent( QTimerEvent *t );
    void resizeEvent( QResizeEvent *event );
    bool event( QEvent *event );
    void dragEnterEvent( QDragEnterEvent *event );
    void dropEvent( QDropEvent *event );
    void closeEvent( QCloseEvent *event );

private slots:
    void on_actionOpen_triggered();
    void on_actionAbout_triggered();
    void on_actionAboutQt_triggered();
    void on_horizontalSliderPosition_valueChanged(int position);
    void on_actionClip_Information_triggered();
    void on_horizontalSliderExposure_valueChanged(int position);
    void on_horizontalSliderTemperature_valueChanged(int position);
    void on_horizontalSliderTint_valueChanged(int position);
    void on_horizontalSliderSaturation_valueChanged(int position);
    void on_horizontalSliderDS_valueChanged(int position);
    void on_horizontalSliderDR_valueChanged(int position);
    void on_horizontalSliderLS_valueChanged(int position);
    void on_horizontalSliderLR_valueChanged(int position);
    void on_horizontalSliderLighten_valueChanged(int position);
    void on_horizontalSliderSharpen_valueChanged(int position);
    void on_horizontalSliderChromaBlur_valueChanged(int position);
    void on_actionGoto_First_Frame_triggered();
    void on_actionExport_triggered();
    void on_actionExportActualFrame_triggered();
    void on_checkBoxHighLightReconstruction_toggled(bool checked);
    void on_checkBoxChromaSeparation_toggled(bool checked);
    void on_comboBoxProfile_currentIndexChanged(int index);
    void on_actionZoomFit_triggered(bool on);
    void on_actionZoom100_triggered();
    void on_actionShowHistogram_triggered(void);
    void on_actionShowWaveFormMonitor_triggered(void);
    void on_actionShowParade_triggered(void);
    void on_actionAlwaysUseAMaZE_triggered(bool checked);
    void on_actionExportSettings_triggered();
    void on_actionResetReceipt_triggered();
    void on_actionCopyRecept_triggered();
    void on_actionPasteReceipt_triggered();
    void on_actionNewSession_triggered();
    void on_actionOpenSession_triggered();
    void on_actionSaveSession_triggered();
    void on_actionCaching_triggered( bool checked );
    void on_listWidgetSession_activated(const QModelIndex &index);
    void on_dockWidgetSession_visibilityChanged(bool visible);
    void on_dockWidgetEdit_visibilityChanged(bool visible);
    void on_actionShowAudioTrack_triggered(bool checked);
    void on_listWidgetSession_customContextMenuRequested(const QPoint &pos);
    void deleteFileFromSession( void );
    void rightClickShowFile( void );
    void selectAllFiles( void );
    void pictureCustomContextMenuRequested(const QPoint &pos);
    void on_labelHistogram_customContextMenuRequested(const QPoint &pos);
    void on_label_ExposureVal_doubleClicked( void );
    void on_label_TemperatureVal_doubleClicked( void );
    void on_label_TintVal_doubleClicked( void );
    void on_label_SaturationVal_doubleClicked( void );
    void on_label_DrVal_doubleClicked( void );
    void on_label_DsVal_doubleClicked( void );
    void on_label_LrVal_doubleClicked( void );
    void on_label_LsVal_doubleClicked( void );
    void on_label_LightenVal_doubleClicked( void );
    void on_label_Sharpen_doubleClicked( void );
    void on_label_ChromaBlur_doubleClicked( void );
    void on_labelAudioTrack_sizeChanged( void );
    void on_actionFullscreen_triggered(bool checked);
    void exportHandler( void );
    void on_actionPlay_triggered(bool checked);
    void on_actionShowZebras_triggered();
    void toolButtonFocusPixelsChanged( void );
    void toolButtonFocusPixelsIntMethodChanged( void );
    void toolButtonBadPixelsChanged( void );
    void toolButtonBadPixelsIntMethodChanged( void );
    void toolButtonChromaSmoothChanged( void );
    void toolButtonPatternNoiseChanged( void );
    void toolButtonVerticalStripesChanged( void );
    void on_spinBoxDeflickerTarget_valueChanged(int arg1);
    void toolButtonDualIsoChanged( void );
    void toolButtonDualIsoInterpolationChanged( void );
    void toolButtonDualIsoAliasMapChanged( void );
    void toolButtonDualIsoFullresBlendingChanged( void );
    void on_actionNextFrame_triggered();
    void on_actionPreviousFrame_triggered();
    void on_checkBoxRawFixEnable_clicked(bool checked);
    void on_actionWhiteBalancePicker_toggled(bool checked);
    void whiteBalancePicked( int x, int y );
    void on_groupBoxRawCorrection_toggled(bool arg1);
    void on_groupBoxProcessing_toggled(bool arg1);
    void on_groupBoxDetails_toggled(bool arg1);
    void exportAbort( void );
    void drawFrameReady( void );

private:
    Ui::MainWindow *ui;
    InfoDialog *m_pInfoDialog;
    StatusDialog *m_pStatusDialog;
    Histogram *m_pHistogram;
    WaveFormMonitor *m_pWaveFormMonitor;
    AudioWave *m_pAudioWave;
    AudioPlayback *m_pAudioPlayback;
    RenderFrameThread *m_pRenderThread;
    mlvObject_t *m_pMlvObject;
    processingObject_t *m_pProcessingObject;
    QGraphicsPixmapItem *m_pGraphicsItem;
    GraphicsPickerScene* m_pScene;
    QLabel *m_pCachingStatus;
    QLabel *m_pFpsStatus;
    QLabel *m_pFrameNumber;
    uint8_t *m_pRawImage;
    uint32_t m_cacheSizeMB;
    uint8_t m_codecProfile;
    uint8_t m_codecOption;
    uint8_t m_previewMode;
    bool m_frameChanged;
    int m_currentFrameIndex;
    double m_newPosDropMode;
    bool m_dontDraw;
    bool m_frameStillDrawing;
    bool m_fileLoaded;
    bool m_inOpeningProcess;
    int m_timerId;
    int m_timerCacheId;
    bool m_fpsOverride;
    bool m_tryToSyncAudio;
    bool m_audioExportEnabled;
    double m_frameRate;
    bool m_exportAbortPressed;
    QString m_lastSaveFileName;
    ReceiptSettings *m_pReceiptClipboard;
    QVector<ReceiptSettings*> m_pSessionReceipts;
    QVector<ReceiptSettings*> m_exportQueue;
    int m_lastActiveClipInSession;
    int m_styleSelection;
    void drawFrame( void );
    void openMlv( QString fileName );
    void playbackHandling( int timeDiff );
    void initGui( void );
    void initLib( void );
    void readSettings( void );
    void writeSettings( void );
    void startExportPipe( QString fileName );
    void addFileToSession( QString fileName );
    void openSession( QString fileName );
    void saveSession( QString fileName );
    void deleteSession( void );
    bool isFileInSession( QString fileName );
    void setSliders( ReceiptSettings *sliders );
    void setReceipt( ReceiptSettings *sliders );
    void showFileInEditor( int row );
    void addClipToExportQueue( int row, QString fileName );
    void previewPicture( int row );
    void setPreviewMode( void );
    double getFramerate( void );
    void paintAudioTrack( void );
    void drawZebras( void );
    void drawFrameNumberLabel( void );
    void setToolButtonFocusPixels( int index );
    void setToolButtonFocusPixelsIntMethod( int index );
    void setToolButtonBadPixels( int index );
    void setToolButtonBadPixelsIntMethod( int index );
    void setToolButtonChromaSmooth( int index );
    void setToolButtonPatternNoise( int index );
    void setToolButtonVerticalStripes( int index );
    void setToolButtonDualIso( int index );
    void setToolButtonDualIsoInterpolation( int index );
    void setToolButtonDualIsoAliasMap( int index );
    void setToolButtonDualIsoFullresBlending( int index );
    int toolButtonFocusPixelsCurrentIndex( void );
    int toolButtonFocusPixelsIntMethodCurrentIndex( void );
    int toolButtonBadPixelsCurrentIndex( void );
    int toolButtonBadPixelsIntMethodCurrentIndex( void );
    int toolButtonChromaSmoothCurrentIndex( void );
    int toolButtonPatternNoiseCurrentIndex( void );
    int toolButtonVerticalStripesCurrentIndex( void );
    int toolButtonDualIsoCurrentIndex( void );
    int toolButtonDualIsoInterpolationCurrentIndex( void );
    int toolButtonDualIsoAliasMapCurrentIndex( void );
    int toolButtonDualIsoFullresBlendingCurrentIndex( void );

signals:
    void exportReady( void );
};

#endif // MAINWINDOW_H
