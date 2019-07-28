// Copyright © 2015, skdltmxn
// Licensed under the MIT License <LICENSE.md>
// This file contains structures, function prototypes, and definitions for the NetDfs API
pub const DFS_VOLUME_STATES: ::DWORD = 0xF;
pub const DFS_VOLUME_STATE_OK: ::DWORD = 1;
pub const DFS_VOLUME_STATE_INCONSISTENT: ::DWORD = 2;
pub const DFS_VOLUME_STATE_OFFLINE: ::DWORD = 3;
pub const DFS_VOLUME_STATE_ONLINE: ::DWORD = 4;
pub const DFS_VOLUME_STATE_RESYNCHRONIZE: ::DWORD = 0x10;
pub const DFS_VOLUME_STATE_STANDBY: ::DWORD = 0x20;
pub const DFS_VOLUME_STATE_FORCE_SYNC: ::DWORD = 0x40;
pub const DFS_VOLUME_FLAVORS: ::DWORD = 0x0300;
pub const DFS_VOLUME_FLAVOR_UNUSED1: ::DWORD = 0x0000;
pub const DFS_VOLUME_FLAVOR_STANDALONE: ::DWORD = 0x0100;
pub const DFS_VOLUME_FLAVOR_AD_BLOB: ::DWORD = 0x0200;
pub const DFS_STORAGE_FLAVOR_UNUSED2: ::DWORD = 0x0300;
pub const DFS_STORAGE_STATES: ::ULONG = 0xF;
pub const DFS_STORAGE_STATE_OFFLINE: ::ULONG = 1;
pub const DFS_STORAGE_STATE_ONLINE: ::ULONG = 2;
pub const DFS_STORAGE_STATE_ACTIVE: ::ULONG = 4;
ENUM!{enum DFS_TARGET_PRIORITY_CLASS {
    DfsInvalidPriorityClass = -1i32 as u32,
    DfsSiteCostNormalPriorityClass = 0,
    DfsGlobalHighPriorityClass,
    DfsSiteCostHighPriorityClass,
    DfsSiteCostLowPriorityClass,
    DfsGlobalLowPriorityClass,
}}
STRUCT!{struct DFS_TARGET_PRIORITY {
    TargetPriorityClass: DFS_TARGET_PRIORITY_CLASS,
    TargetPriorityRank: ::USHORT,
    Reserved: ::USHORT,
}}
pub type PDFS_TARGET_PRIORITY = *mut DFS_TARGET_PRIORITY;
STRUCT!{struct DFS_INFO_1 {
    EntryPath: ::LPWSTR,
}}
pub type PDFS_INFO_1 = *mut DFS_INFO_1;
pub type LPDFS_INFO_1 = *mut DFS_INFO_1;
#[cfg(target_arch="x86_64")] STRUCT!{struct DFS_INFO_1_32 {
    EntryPath: ::ULONG,
}}
#[cfg(target_arch="x86_64")]
pub type PDFS_INFO_1_32 = *mut DFS_INFO_1_32;
#[cfg(target_arch="x86_64")]
pub type LPDFS_INFO_1_32 = *mut DFS_INFO_1_32;
STRUCT!{struct DFS_INFO_2 {
    EntryPath: ::LPWSTR,
    Comment: ::LPWSTR,
    State: ::DWORD,
    NumberOfStorages: ::DWORD,
}}
pub type PDFS_INFO_2 = *mut DFS_INFO_2;
pub type LPDFS_INFO_2 = *mut DFS_INFO_2;
#[cfg(target_arch="x86_64")] STRUCT!{struct DFS_INFO_2_32 {
    EntryPath: ::ULONG,
    Comment: ::ULONG,
    State: ::DWORD,
    NumberOfStorages: ::DWORD,
}}
#[cfg(target_arch="x86_64")]
pub type PDFS_INFO_2_32 = *mut DFS_INFO_2_32;
#[cfg(target_arch="x86_64")]
pub type LPDFS_INFO_2_32 = *mut DFS_INFO_2_32;
STRUCT!{struct DFS_STORAGE_INFO {
    State: ::ULONG,
    ServerName: ::LPWSTR,
    ShareName: ::LPWSTR,
}}
pub type PDFS_STORAGE_INFO = *mut DFS_STORAGE_INFO;
pub type LPDFS_STORAGE_INFO = *mut DFS_STORAGE_INFO;
#[cfg(target_arch="x86_64")] STRUCT!{struct DFS_STORAGE_INFO_0_32 {
    State: ::ULONG,
    ServerName: ::ULONG,
    ShareName: ::ULONG,
}}
#[cfg(target_arch="x86_64")]
pub type PDFS_STORAGE_INFO_0_32 = *mut DFS_STORAGE_INFO_0_32;
#[cfg(target_arch="x86_64")]
pub type LPDFS_STORAGE_INFO_0_32 = *mut DFS_STORAGE_INFO_0_32;
STRUCT!{struct DFS_STORAGE_INFO_1 {
    State: ::ULONG,
    ServerName: ::LPWSTR,
    ShareName: ::LPWSTR,
    TargetPriority: DFS_TARGET_PRIORITY,
}}
pub type PDFS_STORAGE_INFO_1 = *mut DFS_STORAGE_INFO_1;
pub type LPDFS_STORAGE_INFO_1 = *mut DFS_STORAGE_INFO_1;
STRUCT!{struct DFS_INFO_3 {
    EntryPath: ::LPWSTR,
    Comment: ::LPWSTR,
    State: ::DWORD,
    NumberOfStorages: ::DWORD,
    Storage: LPDFS_STORAGE_INFO,
}}
pub type PDFS_INFO_3 = *mut DFS_INFO_3;
pub type LPDFS_INFO_3 = *mut DFS_INFO_3;
#[cfg(target_arch="x86_64")] STRUCT!{struct DFS_INFO_3_32 {
    EntryPath: ::ULONG,
    Comment: ::ULONG,
    State: ::DWORD,
    NumberOfStorages: ::DWORD,
    Storage: ::ULONG,
}}
#[cfg(target_arch="x86_64")]
pub type PDFS_INFO_3_32 = *mut DFS_INFO_3_32;
#[cfg(target_arch="x86_64")]
pub type LPDFS_INFO_3_32 = *mut DFS_INFO_3_32;
STRUCT!{struct DFS_INFO_4 {
    EntryPath: ::LPWSTR,
    Comment: ::LPWSTR,
    State: ::DWORD,
    Timeout: ::ULONG,
    Guid: ::GUID,
    NumberOfStorages: ::DWORD,
    Storage: LPDFS_STORAGE_INFO,
}}
pub type PDFS_INFO_4 = *mut DFS_INFO_4;
pub type LPDFS_INFO_4 = *mut DFS_INFO_4;
#[cfg(target_arch="x86_64")] STRUCT!{struct DFS_INFO_4_32 {
    EntryPath: ::ULONG,
    Comment: ::ULONG,
    State: ::DWORD,
    Timeout: ::ULONG,
    Guid: ::GUID,
    NumberOfStorages: ::DWORD,
    Storage: ::ULONG,
}}
#[cfg(target_arch="x86_64")]
pub type PDFS_INFO_4_32 = *mut DFS_INFO_4_32;
#[cfg(target_arch="x86_64")]
pub type LPDFS_INFO_4_32 = *mut DFS_INFO_4_32;
STRUCT!{struct DFS_INFO_5 {
    EntryPath: ::LPWSTR,
    Comment: ::LPWSTR,
    State: ::DWORD,
    Timeout: ::ULONG,
    Guid: ::GUID,
    PropertyFlags: ::ULONG,
    MetadataSize: ::ULONG,
    NumberOfStorages: ::DWORD,
}}
pub type PDFS_INFO_5 = *mut DFS_INFO_5;
pub type LPDFS_INFO_5 = *mut DFS_INFO_5;
STRUCT!{struct DFS_INFO_6 {
    EntryPath: ::LPWSTR,
    Comment: ::LPWSTR,
    State: ::DWORD,
    Timeout: ::ULONG,
    Guid: ::GUID,
    PropertyFlags: ::ULONG,
    MetadataSize: ::ULONG,
    NumberOfStorages: ::DWORD,
    Storage: LPDFS_STORAGE_INFO,
}}
pub type PDFS_INFO_6 = *mut DFS_INFO_6;
pub type LPDFS_INFO_6 = *mut DFS_INFO_6;
STRUCT!{struct DFS_INFO_7 {
    GenerationGuid: ::GUID,
}}
pub type PDFS_INFO_7 = *mut DFS_INFO_7;
pub type LPDFS_INFO_7 = *mut DFS_INFO_7;
STRUCT!{struct DFS_INFO_8 {
    EntryPath: ::LPWSTR,
    Comment: ::LPWSTR,
    State: ::DWORD,
    Timeout: ::ULONG,
    Guid: ::GUID,
    PropertyFlags: ::ULONG,
    MetadataSize: ::ULONG,
    SdLengthReserved: ::ULONG,
    pSecurityDescriptor: ::PSECURITY_DESCRIPTOR,
    NumberOfStorages: ::DWORD,
}}
pub type PDFS_INFO_8 = *mut DFS_INFO_8;
pub type LPDFS_INFO_8 = *mut DFS_INFO_8;
STRUCT!{struct DFS_INFO_9 {
    EntryPath: ::LPWSTR,
    Comment: ::LPWSTR,
    State: ::DWORD,
    Timeout: ::ULONG,
    Guid: ::GUID,
    PropertyFlags: ::ULONG,
    MetadataSize: ::ULONG,
    SdLengthReserved: ::ULONG,
    pSecurityDescriptor: ::PSECURITY_DESCRIPTOR,
    NumberOfStorages: ::DWORD,
    Storage: LPDFS_STORAGE_INFO,
}}
pub type PDFS_INFO_9 = *mut DFS_INFO_9;
pub type LPDFS_INFO_9 = *mut DFS_INFO_9;
pub const DFS_PROPERTY_FLAG_INSITE_REFERRALS: ::ULONG = 0x00000001;
pub const DFS_PROPERTY_FLAG_ROOT_SCALABILITY: ::ULONG = 0x00000002;
pub const DFS_PROPERTY_FLAG_SITE_COSTING: ::ULONG = 0x00000004;
pub const DFS_PROPERTY_FLAG_TARGET_FAILBACK: ::ULONG = 0x00000008;
pub const DFS_PROPERTY_FLAG_CLUSTER_ENABLED: ::ULONG = 0x00000010;
pub const DFS_PROPERTY_FLAG_ABDE: ::ULONG = 0x00000020;
pub const DFS_VALID_PROPERTY_FLAGS: ::ULONG = DFS_PROPERTY_FLAG_INSITE_REFERRALS
    | DFS_PROPERTY_FLAG_ROOT_SCALABILITY | DFS_PROPERTY_FLAG_SITE_COSTING
    | DFS_PROPERTY_FLAG_TARGET_FAILBACK | DFS_PROPERTY_FLAG_CLUSTER_ENABLED
    | DFS_PROPERTY_FLAG_ABDE;
STRUCT!{struct DFS_INFO_50 {
    NamespaceMajorVersion: ::ULONG,
    NamespaceMinorVersion: ::ULONG,
    NamespaceCapabilities: ::ULONGLONG,
}}
pub type PDFS_INFO_50 = *mut DFS_INFO_50;
pub type LPDFS_INFO_50 = *mut DFS_INFO_50;
STRUCT!{struct DFS_INFO_100 {
    Comment: ::LPWSTR,
}}
pub type PDFS_INFO_100 = *mut DFS_INFO_100;
pub type LPDFS_INFO_100 = *mut DFS_INFO_100;
STRUCT!{struct DFS_INFO_101 {
    State: ::DWORD,
}}
pub type PDFS_INFO_101 = *mut DFS_INFO_101;
pub type LPDFS_INFO_101 = *mut DFS_INFO_101;
STRUCT!{struct DFS_INFO_102 {
    Timeout: ::ULONG,
}}
pub type PDFS_INFO_102 = *mut DFS_INFO_102;
pub type LPDFS_INFO_102 = *mut DFS_INFO_102;
STRUCT!{struct DFS_INFO_103 {
    PropertyFlagMask: ::ULONG,
    PropertyFlags: ::ULONG,
}}
pub type PDFS_INFO_103 = *mut DFS_INFO_103;
pub type LPDFS_INFO_103 = *mut DFS_INFO_103;
STRUCT!{struct DFS_INFO_104 {
    TargetPriority: DFS_TARGET_PRIORITY,
}}
pub type PDFS_INFO_104 = *mut DFS_INFO_104;
pub type LPDFS_INFO_104 = *mut DFS_INFO_104;
STRUCT!{struct DFS_INFO_105 {
    Comment: ::LPWSTR,
    State: ::DWORD,
    Timeout: ::ULONG,
    PropertyFlagMask: ::ULONG,
    PropertyFlags: ::ULONG,
}}
pub type PDFS_INFO_105 = *mut DFS_INFO_105;
pub type LPDFS_INFO_105 = *mut DFS_INFO_105;
STRUCT!{struct DFS_INFO_106 {
    State: ::DWORD,
    TargetPriority: DFS_TARGET_PRIORITY,
}}
pub type PDFS_INFO_106 = *mut DFS_INFO_106;
pub type LPDFS_INFO_106 = *mut DFS_INFO_106;
STRUCT!{struct DFS_INFO_107 {
    Comment: ::LPWSTR,
    State: ::DWORD,
    Timeout: ::ULONG,
    PropertyFlagMask: ::ULONG,
    PropertyFlags: ::ULONG,
    SdLengthReserved: ::ULONG,
    pSecurityDescriptor: ::PSECURITY_DESCRIPTOR,
}}
pub type PDFS_INFO_107 = *mut DFS_INFO_107;
pub type LPDFS_INFO_107 = *mut DFS_INFO_107;
STRUCT!{struct DFS_INFO_150 {
    SdLengthReserved: ::ULONG,
    pSecurityDescriptor: ::PSECURITY_DESCRIPTOR,
}}
pub type PDFS_INFO_150 = *mut DFS_INFO_150;
pub type LPDFS_INFO_150 = *mut DFS_INFO_150;
STRUCT!{struct DFS_INFO_200 {
    FtDfsName: ::LPWSTR,
}}
pub type PDFS_INFO_200 = *mut DFS_INFO_200;
pub type LPDFS_INFO_200 = *mut DFS_INFO_200;
STRUCT!{struct DFS_INFO_300 {
    Flags: ::DWORD,
    DfsName: ::LPWSTR,
}}
pub type PDFS_INFO_300 = *mut DFS_INFO_300;
pub type LPDFS_INFO_300 = *mut DFS_INFO_300;
pub const DFS_ADD_VOLUME: ::DWORD = 1;
pub const DFS_RESTORE_VOLUME: ::DWORD = 2;
pub const NET_DFS_SETDC_FLAGS: ::DWORD = 0x00000000;
pub const NET_DFS_SETDC_TIMEOUT: ::DWORD = 0x00000001;
pub const NET_DFS_SETDC_INITPKT: ::DWORD = 0x00000002;
STRUCT!{struct DFS_SITENAME_INFO {
    SiteFlags: ::ULONG,
    SiteName: ::LPWSTR,
}}
pub type PDFS_SITENAME_INFO = *mut DFS_SITENAME_INFO;
pub type LPDFS_SITENAME_INFO = *mut DFS_SITENAME_INFO;
pub const DFS_SITE_PRIMARY: ::ULONG = 0x1;
STRUCT!{struct DFS_SITELIST_INFO {
    cSites: ::ULONG,
    Site: [DFS_SITENAME_INFO; 1],
}}
pub type PDFS_SITELIST_INFO = *mut DFS_SITELIST_INFO;
pub type LPDFS_SITELIST_INFO = *mut DFS_SITELIST_INFO;
ENUM!{enum DFS_NAMESPACE_VERSION_ORIGIN {
    DFS_NAMESPACE_VERSION_ORIGIN_COMBINED = 0,
    DFS_NAMESPACE_VERSION_ORIGIN_SERVER,
    DFS_NAMESPACE_VERSION_ORIGIN_DOMAIN,
}}
pub type PDFS_NAMESPACE_VERSION_ORIGIN = *mut DFS_NAMESPACE_VERSION_ORIGIN;
pub const DFS_NAMESPACE_CAPABILITY_ABDE: ::ULONGLONG = 0x0000000000000001;
STRUCT!{struct DFS_SUPPORTED_NAMESPACE_VERSION_INFO {
    DomainDfsMajorVersion: ::ULONG,
    DomainDfsMinorVersion: ::ULONG,
    DomainDfsCapabilities: ::ULONGLONG,
    StandaloneDfsMajorVersion: ::ULONG,
    StandaloneDfsMinorVersion: ::ULONG,
    StandaloneDfsCapabilities: ::ULONGLONG,
}}
pub type PDFS_SUPPORTED_NAMESPACE_VERSION_INFO = *mut DFS_SUPPORTED_NAMESPACE_VERSION_INFO;
