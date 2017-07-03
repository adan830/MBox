#pragma once

namespace MBox
{
    namespace MiniFlt
    {
        using fun$FltUnload = NTSTATUS(*)(FLT_FILTER_UNLOAD_FLAGS aFlags, void* aParameter);

        NTSTATUS Initialize(
            DRIVER_OBJECT* aDriverObject,
            UNICODE_STRING* /*aRegistryPath*/,
            fun$FltUnload aPreUnload,
            void* aPreUnloadParameter,
            fun$FltUnload aPostUnload,
            void* aPostUnloadParameter);

        NTSTATUS Uninitialize();

        NTSTATUS RegisterFilter(
            System::SystemVersion aVersion,
            FLT_CONTEXT_TYPE aContextSupportedType,
            FLT_REGISTRATION_FLAGS aFltRegistrationFlags);
        NTSTATUS UnregisterFilter();

        NTSTATUS StartFilter();
        NTSTATUS StopFilter();
        BOOLEAN IsStartedFilter();

        PFLT_FILTER GetFilterHandle();
    }
}
