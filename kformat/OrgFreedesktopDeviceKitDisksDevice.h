/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp /usr/share/dbus-1/interfaces/org.freedesktop.DeviceKit.Disks.Device.xml -m -p OrgFreedesktopDeviceKitDisksDevice
 *
 * qdbusxml2cpp is Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef ORGFREEDESKTOPDEVICEKITDISKSDEVICE_H_1253492026
#define ORGFREEDESKTOPDEVICEKITDISKSDEVICE_H_1253492026

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface org.freedesktop.DeviceKit.Disks.Device
 */
class OrgFreedesktopDeviceKitDisksDeviceInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freedesktop.DeviceKit.Disks.Device"; }

public:
    OrgFreedesktopDeviceKitDisksDeviceInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~OrgFreedesktopDeviceKitDisksDeviceInterface();

    Q_PROPERTY(qulonglong DeviceBlockSize READ deviceBlockSize)
    inline qulonglong deviceBlockSize() const
    { return qvariant_cast< qulonglong >(internalPropGet("DeviceBlockSize")); }

    Q_PROPERTY(qulonglong DeviceDetectionTime READ deviceDetectionTime)
    inline qulonglong deviceDetectionTime() const
    { return qvariant_cast< qulonglong >(internalPropGet("DeviceDetectionTime")); }

    Q_PROPERTY(QString DeviceFile READ deviceFile)
    inline QString deviceFile() const
    { return qvariant_cast< QString >(internalPropGet("DeviceFile")); }

    Q_PROPERTY(QStringList DeviceFileById READ deviceFileById)
    inline QStringList deviceFileById() const
    { return qvariant_cast< QStringList >(internalPropGet("DeviceFileById")); }

    Q_PROPERTY(QStringList DeviceFileByPath READ deviceFileByPath)
    inline QStringList deviceFileByPath() const
    { return qvariant_cast< QStringList >(internalPropGet("DeviceFileByPath")); }

    Q_PROPERTY(bool DeviceIsDrive READ deviceIsDrive)
    inline bool deviceIsDrive() const
    { return qvariant_cast< bool >(internalPropGet("DeviceIsDrive")); }

    Q_PROPERTY(bool DeviceIsLinuxMd READ deviceIsLinuxMd)
    inline bool deviceIsLinuxMd() const
    { return qvariant_cast< bool >(internalPropGet("DeviceIsLinuxMd")); }

    Q_PROPERTY(bool DeviceIsLinuxMdComponent READ deviceIsLinuxMdComponent)
    inline bool deviceIsLinuxMdComponent() const
    { return qvariant_cast< bool >(internalPropGet("DeviceIsLinuxMdComponent")); }

    Q_PROPERTY(bool DeviceIsLuks READ deviceIsLuks)
    inline bool deviceIsLuks() const
    { return qvariant_cast< bool >(internalPropGet("DeviceIsLuks")); }

    Q_PROPERTY(bool DeviceIsLuksCleartext READ deviceIsLuksCleartext)
    inline bool deviceIsLuksCleartext() const
    { return qvariant_cast< bool >(internalPropGet("DeviceIsLuksCleartext")); }

    Q_PROPERTY(bool DeviceIsMediaAvailable READ deviceIsMediaAvailable)
    inline bool deviceIsMediaAvailable() const
    { return qvariant_cast< bool >(internalPropGet("DeviceIsMediaAvailable")); }

    Q_PROPERTY(bool DeviceIsMediaChangeDetected READ deviceIsMediaChangeDetected)
    inline bool deviceIsMediaChangeDetected() const
    { return qvariant_cast< bool >(internalPropGet("DeviceIsMediaChangeDetected")); }

    Q_PROPERTY(bool DeviceIsMediaChangeDetectionInhibitable READ deviceIsMediaChangeDetectionInhibitable)
    inline bool deviceIsMediaChangeDetectionInhibitable() const
    { return qvariant_cast< bool >(internalPropGet("DeviceIsMediaChangeDetectionInhibitable")); }

    Q_PROPERTY(bool DeviceIsMediaChangeDetectionInhibited READ deviceIsMediaChangeDetectionInhibited)
    inline bool deviceIsMediaChangeDetectionInhibited() const
    { return qvariant_cast< bool >(internalPropGet("DeviceIsMediaChangeDetectionInhibited")); }

    Q_PROPERTY(bool DeviceIsMediaChangeDetectionPolling READ deviceIsMediaChangeDetectionPolling)
    inline bool deviceIsMediaChangeDetectionPolling() const
    { return qvariant_cast< bool >(internalPropGet("DeviceIsMediaChangeDetectionPolling")); }

    Q_PROPERTY(bool DeviceIsMounted READ deviceIsMounted)
    inline bool deviceIsMounted() const
    { return qvariant_cast< bool >(internalPropGet("DeviceIsMounted")); }

    Q_PROPERTY(bool DeviceIsOpticalDisc READ deviceIsOpticalDisc)
    inline bool deviceIsOpticalDisc() const
    { return qvariant_cast< bool >(internalPropGet("DeviceIsOpticalDisc")); }

    Q_PROPERTY(bool DeviceIsPartition READ deviceIsPartition)
    inline bool deviceIsPartition() const
    { return qvariant_cast< bool >(internalPropGet("DeviceIsPartition")); }

    Q_PROPERTY(bool DeviceIsPartitionTable READ deviceIsPartitionTable)
    inline bool deviceIsPartitionTable() const
    { return qvariant_cast< bool >(internalPropGet("DeviceIsPartitionTable")); }

    Q_PROPERTY(bool DeviceIsReadOnly READ deviceIsReadOnly)
    inline bool deviceIsReadOnly() const
    { return qvariant_cast< bool >(internalPropGet("DeviceIsReadOnly")); }

    Q_PROPERTY(bool DeviceIsRemovable READ deviceIsRemovable)
    inline bool deviceIsRemovable() const
    { return qvariant_cast< bool >(internalPropGet("DeviceIsRemovable")); }

    Q_PROPERTY(bool DeviceIsSystemInternal READ deviceIsSystemInternal)
    inline bool deviceIsSystemInternal() const
    { return qvariant_cast< bool >(internalPropGet("DeviceIsSystemInternal")); }

    Q_PROPERTY(qlonglong DeviceMajor READ deviceMajor)
    inline qlonglong deviceMajor() const
    { return qvariant_cast< qlonglong >(internalPropGet("DeviceMajor")); }

    Q_PROPERTY(qulonglong DeviceMediaDetectionTime READ deviceMediaDetectionTime)
    inline qulonglong deviceMediaDetectionTime() const
    { return qvariant_cast< qulonglong >(internalPropGet("DeviceMediaDetectionTime")); }

    Q_PROPERTY(qlonglong DeviceMinor READ deviceMinor)
    inline qlonglong deviceMinor() const
    { return qvariant_cast< qlonglong >(internalPropGet("DeviceMinor")); }

    Q_PROPERTY(QStringList DeviceMountPaths READ deviceMountPaths)
    inline QStringList deviceMountPaths() const
    { return qvariant_cast< QStringList >(internalPropGet("DeviceMountPaths")); }

    Q_PROPERTY(uint DeviceMountedByUid READ deviceMountedByUid)
    inline uint deviceMountedByUid() const
    { return qvariant_cast< uint >(internalPropGet("DeviceMountedByUid")); }

    Q_PROPERTY(bool DevicePresentationHide READ devicePresentationHide)
    inline bool devicePresentationHide() const
    { return qvariant_cast< bool >(internalPropGet("DevicePresentationHide")); }

    Q_PROPERTY(QString DevicePresentationIconName READ devicePresentationIconName)
    inline QString devicePresentationIconName() const
    { return qvariant_cast< QString >(internalPropGet("DevicePresentationIconName")); }

    Q_PROPERTY(QString DevicePresentationName READ devicePresentationName)
    inline QString devicePresentationName() const
    { return qvariant_cast< QString >(internalPropGet("DevicePresentationName")); }

    Q_PROPERTY(bool DevicePresentationNopolicy READ devicePresentationNopolicy)
    inline bool devicePresentationNopolicy() const
    { return qvariant_cast< bool >(internalPropGet("DevicePresentationNopolicy")); }

    Q_PROPERTY(qulonglong DeviceSize READ deviceSize)
    inline qulonglong deviceSize() const
    { return qvariant_cast< qulonglong >(internalPropGet("DeviceSize")); }

    Q_PROPERTY(QByteArray DriveAtaSmartBlob READ driveAtaSmartBlob)
    inline QByteArray driveAtaSmartBlob() const
    { return qvariant_cast< QByteArray >(internalPropGet("DriveAtaSmartBlob")); }

    Q_PROPERTY(bool DriveAtaSmartIsAvailable READ driveAtaSmartIsAvailable)
    inline bool driveAtaSmartIsAvailable() const
    { return qvariant_cast< bool >(internalPropGet("DriveAtaSmartIsAvailable")); }

    Q_PROPERTY(QString DriveAtaSmartStatus READ driveAtaSmartStatus)
    inline QString driveAtaSmartStatus() const
    { return qvariant_cast< QString >(internalPropGet("DriveAtaSmartStatus")); }

    Q_PROPERTY(qulonglong DriveAtaSmartTimeCollected READ driveAtaSmartTimeCollected)
    inline qulonglong driveAtaSmartTimeCollected() const
    { return qvariant_cast< qulonglong >(internalPropGet("DriveAtaSmartTimeCollected")); }

    Q_PROPERTY(bool DriveCanDetach READ driveCanDetach)
    inline bool driveCanDetach() const
    { return qvariant_cast< bool >(internalPropGet("DriveCanDetach")); }

    Q_PROPERTY(bool DriveCanSpindown READ driveCanSpindown)
    inline bool driveCanSpindown() const
    { return qvariant_cast< bool >(internalPropGet("DriveCanSpindown")); }

    Q_PROPERTY(QString DriveConnectionInterface READ driveConnectionInterface)
    inline QString driveConnectionInterface() const
    { return qvariant_cast< QString >(internalPropGet("DriveConnectionInterface")); }

    Q_PROPERTY(qulonglong DriveConnectionSpeed READ driveConnectionSpeed)
    inline qulonglong driveConnectionSpeed() const
    { return qvariant_cast< qulonglong >(internalPropGet("DriveConnectionSpeed")); }

    Q_PROPERTY(bool DriveIsMediaEjectable READ driveIsMediaEjectable)
    inline bool driveIsMediaEjectable() const
    { return qvariant_cast< bool >(internalPropGet("DriveIsMediaEjectable")); }

    Q_PROPERTY(bool DriveIsRotational READ driveIsRotational)
    inline bool driveIsRotational() const
    { return qvariant_cast< bool >(internalPropGet("DriveIsRotational")); }

    Q_PROPERTY(QString DriveMedia READ driveMedia)
    inline QString driveMedia() const
    { return qvariant_cast< QString >(internalPropGet("DriveMedia")); }

    Q_PROPERTY(QStringList DriveMediaCompatibility READ driveMediaCompatibility)
    inline QStringList driveMediaCompatibility() const
    { return qvariant_cast< QStringList >(internalPropGet("DriveMediaCompatibility")); }

    Q_PROPERTY(QString DriveModel READ driveModel)
    inline QString driveModel() const
    { return qvariant_cast< QString >(internalPropGet("DriveModel")); }

    Q_PROPERTY(QString DriveRevision READ driveRevision)
    inline QString driveRevision() const
    { return qvariant_cast< QString >(internalPropGet("DriveRevision")); }

    Q_PROPERTY(QString DriveSerial READ driveSerial)
    inline QString driveSerial() const
    { return qvariant_cast< QString >(internalPropGet("DriveSerial")); }

    Q_PROPERTY(QString DriveVendor READ driveVendor)
    inline QString driveVendor() const
    { return qvariant_cast< QString >(internalPropGet("DriveVendor")); }

    Q_PROPERTY(QString IdLabel READ idLabel)
    inline QString idLabel() const
    { return qvariant_cast< QString >(internalPropGet("IdLabel")); }

    Q_PROPERTY(QString IdType READ idType)
    inline QString idType() const
    { return qvariant_cast< QString >(internalPropGet("IdType")); }

    Q_PROPERTY(QString IdUsage READ idUsage)
    inline QString idUsage() const
    { return qvariant_cast< QString >(internalPropGet("IdUsage")); }

    Q_PROPERTY(QString IdUuid READ idUuid)
    inline QString idUuid() const
    { return qvariant_cast< QString >(internalPropGet("IdUuid")); }

    Q_PROPERTY(QString IdVersion READ idVersion)
    inline QString idVersion() const
    { return qvariant_cast< QString >(internalPropGet("IdVersion")); }

    Q_PROPERTY(QString JobId READ jobId)
    inline QString jobId() const
    { return qvariant_cast< QString >(internalPropGet("JobId")); }

    Q_PROPERTY(bool JobInProgress READ jobInProgress)
    inline bool jobInProgress() const
    { return qvariant_cast< bool >(internalPropGet("JobInProgress")); }

    Q_PROPERTY(uint JobInitiatedByUid READ jobInitiatedByUid)
    inline uint jobInitiatedByUid() const
    { return qvariant_cast< uint >(internalPropGet("JobInitiatedByUid")); }

    Q_PROPERTY(bool JobIsCancellable READ jobIsCancellable)
    inline bool jobIsCancellable() const
    { return qvariant_cast< bool >(internalPropGet("JobIsCancellable")); }

    Q_PROPERTY(double JobPercentage READ jobPercentage)
    inline double jobPercentage() const
    { return qvariant_cast< double >(internalPropGet("JobPercentage")); }

    Q_PROPERTY(QDBusObjectPath LinuxMdComponentHolder READ linuxMdComponentHolder)
    inline QDBusObjectPath linuxMdComponentHolder() const
    { return qvariant_cast< QDBusObjectPath >(internalPropGet("LinuxMdComponentHolder")); }

    Q_PROPERTY(QString LinuxMdComponentHomeHost READ linuxMdComponentHomeHost)
    inline QString linuxMdComponentHomeHost() const
    { return qvariant_cast< QString >(internalPropGet("LinuxMdComponentHomeHost")); }

    Q_PROPERTY(QString LinuxMdComponentLevel READ linuxMdComponentLevel)
    inline QString linuxMdComponentLevel() const
    { return qvariant_cast< QString >(internalPropGet("LinuxMdComponentLevel")); }

    Q_PROPERTY(QString LinuxMdComponentName READ linuxMdComponentName)
    inline QString linuxMdComponentName() const
    { return qvariant_cast< QString >(internalPropGet("LinuxMdComponentName")); }

    Q_PROPERTY(int LinuxMdComponentNumRaidDevices READ linuxMdComponentNumRaidDevices)
    inline int linuxMdComponentNumRaidDevices() const
    { return qvariant_cast< int >(internalPropGet("LinuxMdComponentNumRaidDevices")); }

    Q_PROPERTY(QStringList LinuxMdComponentState READ linuxMdComponentState)
    inline QStringList linuxMdComponentState() const
    { return qvariant_cast< QStringList >(internalPropGet("LinuxMdComponentState")); }

    Q_PROPERTY(QString LinuxMdComponentUuid READ linuxMdComponentUuid)
    inline QString linuxMdComponentUuid() const
    { return qvariant_cast< QString >(internalPropGet("LinuxMdComponentUuid")); }

    Q_PROPERTY(QString LinuxMdComponentVersion READ linuxMdComponentVersion)
    inline QString linuxMdComponentVersion() const
    { return qvariant_cast< QString >(internalPropGet("LinuxMdComponentVersion")); }

    Q_PROPERTY(QString LinuxMdHomeHost READ linuxMdHomeHost)
    inline QString linuxMdHomeHost() const
    { return qvariant_cast< QString >(internalPropGet("LinuxMdHomeHost")); }

    Q_PROPERTY(bool LinuxMdIsDegraded READ linuxMdIsDegraded)
    inline bool linuxMdIsDegraded() const
    { return qvariant_cast< bool >(internalPropGet("LinuxMdIsDegraded")); }

    Q_PROPERTY(QString LinuxMdLevel READ linuxMdLevel)
    inline QString linuxMdLevel() const
    { return qvariant_cast< QString >(internalPropGet("LinuxMdLevel")); }

    Q_PROPERTY(QString LinuxMdName READ linuxMdName)
    inline QString linuxMdName() const
    { return qvariant_cast< QString >(internalPropGet("LinuxMdName")); }

    Q_PROPERTY(int LinuxMdNumRaidDevices READ linuxMdNumRaidDevices)
    inline int linuxMdNumRaidDevices() const
    { return qvariant_cast< int >(internalPropGet("LinuxMdNumRaidDevices")); }

    Q_PROPERTY(QList<QDBusObjectPath> LinuxMdSlaves READ linuxMdSlaves)
    inline QList<QDBusObjectPath> linuxMdSlaves() const
    { return qvariant_cast< QList<QDBusObjectPath> >(internalPropGet("LinuxMdSlaves")); }

    Q_PROPERTY(QString LinuxMdState READ linuxMdState)
    inline QString linuxMdState() const
    { return qvariant_cast< QString >(internalPropGet("LinuxMdState")); }

    Q_PROPERTY(QString LinuxMdSyncAction READ linuxMdSyncAction)
    inline QString linuxMdSyncAction() const
    { return qvariant_cast< QString >(internalPropGet("LinuxMdSyncAction")); }

    Q_PROPERTY(double LinuxMdSyncPercentage READ linuxMdSyncPercentage)
    inline double linuxMdSyncPercentage() const
    { return qvariant_cast< double >(internalPropGet("LinuxMdSyncPercentage")); }

    Q_PROPERTY(qulonglong LinuxMdSyncSpeed READ linuxMdSyncSpeed)
    inline qulonglong linuxMdSyncSpeed() const
    { return qvariant_cast< qulonglong >(internalPropGet("LinuxMdSyncSpeed")); }

    Q_PROPERTY(QString LinuxMdUuid READ linuxMdUuid)
    inline QString linuxMdUuid() const
    { return qvariant_cast< QString >(internalPropGet("LinuxMdUuid")); }

    Q_PROPERTY(QString LinuxMdVersion READ linuxMdVersion)
    inline QString linuxMdVersion() const
    { return qvariant_cast< QString >(internalPropGet("LinuxMdVersion")); }

    Q_PROPERTY(QDBusObjectPath LuksCleartextSlave READ luksCleartextSlave)
    inline QDBusObjectPath luksCleartextSlave() const
    { return qvariant_cast< QDBusObjectPath >(internalPropGet("LuksCleartextSlave")); }

    Q_PROPERTY(uint LuksCleartextUnlockedByUid READ luksCleartextUnlockedByUid)
    inline uint luksCleartextUnlockedByUid() const
    { return qvariant_cast< uint >(internalPropGet("LuksCleartextUnlockedByUid")); }

    Q_PROPERTY(QDBusObjectPath LuksHolder READ luksHolder)
    inline QDBusObjectPath luksHolder() const
    { return qvariant_cast< QDBusObjectPath >(internalPropGet("LuksHolder")); }

    Q_PROPERTY(QString NativePath READ nativePath)
    inline QString nativePath() const
    { return qvariant_cast< QString >(internalPropGet("NativePath")); }

    Q_PROPERTY(bool OpticalDiscIsAppendable READ opticalDiscIsAppendable)
    inline bool opticalDiscIsAppendable() const
    { return qvariant_cast< bool >(internalPropGet("OpticalDiscIsAppendable")); }

    Q_PROPERTY(bool OpticalDiscIsBlank READ opticalDiscIsBlank)
    inline bool opticalDiscIsBlank() const
    { return qvariant_cast< bool >(internalPropGet("OpticalDiscIsBlank")); }

    Q_PROPERTY(bool OpticalDiscIsClosed READ opticalDiscIsClosed)
    inline bool opticalDiscIsClosed() const
    { return qvariant_cast< bool >(internalPropGet("OpticalDiscIsClosed")); }

    Q_PROPERTY(uint OpticalDiscNumAudioTracks READ opticalDiscNumAudioTracks)
    inline uint opticalDiscNumAudioTracks() const
    { return qvariant_cast< uint >(internalPropGet("OpticalDiscNumAudioTracks")); }

    Q_PROPERTY(uint OpticalDiscNumSessions READ opticalDiscNumSessions)
    inline uint opticalDiscNumSessions() const
    { return qvariant_cast< uint >(internalPropGet("OpticalDiscNumSessions")); }

    Q_PROPERTY(uint OpticalDiscNumTracks READ opticalDiscNumTracks)
    inline uint opticalDiscNumTracks() const
    { return qvariant_cast< uint >(internalPropGet("OpticalDiscNumTracks")); }

    Q_PROPERTY(QStringList PartitionFlags READ partitionFlags)
    inline QStringList partitionFlags() const
    { return qvariant_cast< QStringList >(internalPropGet("PartitionFlags")); }

    Q_PROPERTY(QString PartitionLabel READ partitionLabel)
    inline QString partitionLabel() const
    { return qvariant_cast< QString >(internalPropGet("PartitionLabel")); }

    Q_PROPERTY(int PartitionNumber READ partitionNumber)
    inline int partitionNumber() const
    { return qvariant_cast< int >(internalPropGet("PartitionNumber")); }

    Q_PROPERTY(qulonglong PartitionOffset READ partitionOffset)
    inline qulonglong partitionOffset() const
    { return qvariant_cast< qulonglong >(internalPropGet("PartitionOffset")); }

    Q_PROPERTY(QString PartitionScheme READ partitionScheme)
    inline QString partitionScheme() const
    { return qvariant_cast< QString >(internalPropGet("PartitionScheme")); }

    Q_PROPERTY(qulonglong PartitionSize READ partitionSize)
    inline qulonglong partitionSize() const
    { return qvariant_cast< qulonglong >(internalPropGet("PartitionSize")); }

    Q_PROPERTY(QDBusObjectPath PartitionSlave READ partitionSlave)
    inline QDBusObjectPath partitionSlave() const
    { return qvariant_cast< QDBusObjectPath >(internalPropGet("PartitionSlave")); }

    Q_PROPERTY(int PartitionTableCount READ partitionTableCount)
    inline int partitionTableCount() const
    { return qvariant_cast< int >(internalPropGet("PartitionTableCount")); }

    Q_PROPERTY(QString PartitionTableScheme READ partitionTableScheme)
    inline QString partitionTableScheme() const
    { return qvariant_cast< QString >(internalPropGet("PartitionTableScheme")); }

    Q_PROPERTY(QString PartitionType READ partitionType)
    inline QString partitionType() const
    { return qvariant_cast< QString >(internalPropGet("PartitionType")); }

    Q_PROPERTY(QString PartitionUuid READ partitionUuid)
    inline QString partitionUuid() const
    { return qvariant_cast< QString >(internalPropGet("PartitionUuid")); }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> DriveAtaSmartInitiateSelftest(const QString &test, const QStringList &options)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(test) << qVariantFromValue(options);
        return asyncCallWithArgumentList(QLatin1String("DriveAtaSmartInitiateSelftest"), argumentList);
    }

    inline QDBusPendingReply<> DriveAtaSmartRefreshData(const QStringList &options)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(options);
        return asyncCallWithArgumentList(QLatin1String("DriveAtaSmartRefreshData"), argumentList);
    }

    inline QDBusPendingReply<> DriveDetach(const QStringList &options)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(options);
        return asyncCallWithArgumentList(QLatin1String("DriveDetach"), argumentList);
    }

    inline QDBusPendingReply<> DriveEject(const QStringList &options)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(options);
        return asyncCallWithArgumentList(QLatin1String("DriveEject"), argumentList);
    }

    inline QDBusPendingReply<QString> DriveInhibitPolling(const QStringList &options)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(options);
        return asyncCallWithArgumentList(QLatin1String("DriveInhibitPolling"), argumentList);
    }

    inline QDBusPendingReply<> DrivePollMedia()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("DrivePollMedia"), argumentList);
    }

    inline QDBusPendingReply<QString> DriveSetSpindownTimeout(int timeout_seconds, const QStringList &options)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(timeout_seconds) << qVariantFromValue(options);
        return asyncCallWithArgumentList(QLatin1String("DriveSetSpindownTimeout"), argumentList);
    }

    inline QDBusPendingReply<> DriveUninhibitPolling(const QString &cookie)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(cookie);
        return asyncCallWithArgumentList(QLatin1String("DriveUninhibitPolling"), argumentList);
    }

    inline QDBusPendingReply<> DriveUnsetSpindownTimeout(const QString &cookie)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(cookie);
        return asyncCallWithArgumentList(QLatin1String("DriveUnsetSpindownTimeout"), argumentList);
    }

    inline QDBusPendingReply<bool> FilesystemCheck(const QStringList &options)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(options);
        return asyncCallWithArgumentList(QLatin1String("FilesystemCheck"), argumentList);
    }

    inline QDBusPendingReply<> FilesystemCreate(const QString &fstype, const QStringList &options)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(fstype) << qVariantFromValue(options);
        return asyncCallWithArgumentList(QLatin1String("FilesystemCreate"), argumentList);
    }

    inline QDBusPendingReply<QVariant> FilesystemListOpenFiles()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("FilesystemListOpenFiles"), argumentList);
    }

    inline QDBusPendingReply<QString> FilesystemMount(const QString &filesystem_type, const QStringList &options)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(filesystem_type) << qVariantFromValue(options);
        return asyncCallWithArgumentList(QLatin1String("FilesystemMount"), argumentList);
    }

    inline QDBusPendingReply<> FilesystemSetLabel(const QString &new_label)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(new_label);
        return asyncCallWithArgumentList(QLatin1String("FilesystemSetLabel"), argumentList);
    }

    inline QDBusPendingReply<> FilesystemUnmount(const QStringList &options)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(options);
        return asyncCallWithArgumentList(QLatin1String("FilesystemUnmount"), argumentList);
    }

    inline QDBusPendingReply<> JobCancel()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("JobCancel"), argumentList);
    }

    inline QDBusPendingReply<> LinuxMdAddComponent(const QDBusObjectPath &component, const QStringList &options)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(component) << qVariantFromValue(options);
        return asyncCallWithArgumentList(QLatin1String("LinuxMdAddComponent"), argumentList);
    }

    inline QDBusPendingReply<qulonglong> LinuxMdCheck(const QStringList &options)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(options);
        return asyncCallWithArgumentList(QLatin1String("LinuxMdCheck"), argumentList);
    }

    inline QDBusPendingReply<> LinuxMdRemoveComponent(const QDBusObjectPath &component, const QStringList &options)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(component) << qVariantFromValue(options);
        return asyncCallWithArgumentList(QLatin1String("LinuxMdRemoveComponent"), argumentList);
    }

    inline QDBusPendingReply<> LinuxMdStop(const QStringList &options)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(options);
        return asyncCallWithArgumentList(QLatin1String("LinuxMdStop"), argumentList);
    }

    inline QDBusPendingReply<> LuksChangePassphrase(const QString &current_passphrase, const QString &new_passphrase)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(current_passphrase) << qVariantFromValue(new_passphrase);
        return asyncCallWithArgumentList(QLatin1String("LuksChangePassphrase"), argumentList);
    }

    inline QDBusPendingReply<> LuksLock(const QStringList &options)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(options);
        return asyncCallWithArgumentList(QLatin1String("LuksLock"), argumentList);
    }

    inline QDBusPendingReply<QDBusObjectPath> LuksUnlock(const QString &passphrase, const QStringList &options)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(passphrase) << qVariantFromValue(options);
        return asyncCallWithArgumentList(QLatin1String("LuksUnlock"), argumentList);
    }

    inline QDBusPendingReply<QDBusObjectPath> PartitionCreate(qulonglong offset, qulonglong size, const QString &type, const QString &label, const QStringList &flags, const QStringList &options, const QString &fstype, const QStringList &fsoptions)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(offset) << qVariantFromValue(size) << qVariantFromValue(type) << qVariantFromValue(label) << qVariantFromValue(flags) << qVariantFromValue(options) << qVariantFromValue(fstype) << qVariantFromValue(fsoptions);
        return asyncCallWithArgumentList(QLatin1String("PartitionCreate"), argumentList);
    }

    inline QDBusPendingReply<> PartitionDelete(const QStringList &options)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(options);
        return asyncCallWithArgumentList(QLatin1String("PartitionDelete"), argumentList);
    }

    inline QDBusPendingReply<> PartitionModify(const QString &type, const QString &label, const QStringList &flags)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(type) << qVariantFromValue(label) << qVariantFromValue(flags);
        return asyncCallWithArgumentList(QLatin1String("PartitionModify"), argumentList);
    }

    inline QDBusPendingReply<> PartitionTableCreate(const QString &scheme, const QStringList &options)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(scheme) << qVariantFromValue(options);
        return asyncCallWithArgumentList(QLatin1String("PartitionTableCreate"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void Changed();
    void JobChanged(bool jobinprogress, bool jobiscancellable, const QString &jobid, uint jobinitiatedbyuid, double jobpercentage);
};

namespace org {
  namespace freedesktop {
    namespace DeviceKit {
        typedef ::OrgFreedesktopDeviceKitDisksDeviceInterface Device;
    }
  }
}
#endif