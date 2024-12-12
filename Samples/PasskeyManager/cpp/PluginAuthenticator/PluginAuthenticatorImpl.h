#pragma once
#include <pch.h>
#include <App.xaml.h>
#include <winrt/Microsoft.UI.Xaml.h>
#include <winrt/Microsoft.UI.Xaml.Controls.h>
#include <vector>

static constexpr GUID contosoplugin_guid // 7fa07696-e94e-4a72-b8fd-6890c5897a35
{
    0x7fa07696, 0xe94e, 0x4a72, { 0xb8, 0xfd, 0x68, 0x90, 0xc5, 0x89, 0x7a, 0x35 }
};

static constexpr wchar_t contosoplugin_key_domain[] = L"contoso/";

namespace winrt::PasskeyManager::implementation
{
    struct ContosoPlugin : winrt::implements<ContosoPlugin, EXPERIMENTAL_IPluginAuthenticator>
    {
        HRESULT __stdcall EXPERIMENTAL_PluginMakeCredential(__RPC__in EXPERIMENTAL_PCWEBAUTHN_PLUGIN_OPERATION_REQUEST pPluginMakeCredentialRequest, __RPC__deref_out_opt EXPERIMENTAL_PWEBAUTHN_PLUGIN_OPERATION_RESPONSE* response) noexcept;
        HRESULT __stdcall EXPERIMENTAL_PluginGetAssertion(__RPC__in EXPERIMENTAL_PCWEBAUTHN_PLUGIN_OPERATION_REQUEST pPluginGetAssertionRequest, __RPC__deref_out_opt EXPERIMENTAL_PWEBAUTHN_PLUGIN_OPERATION_RESPONSE* response) noexcept;
        HRESULT __stdcall EXPERIMENTAL_PluginCancelOperation(__RPC__in EXPERIMENTAL_PCWEBAUTHN_PLUGIN_CANCEL_OPERATION_REQUEST pCancelRequest);
    };

    struct ContosoPluginFactory : implements<ContosoPluginFactory, IClassFactory>
    {
        HRESULT __stdcall CreateInstance(::IUnknown* outer, GUID const& iid, void** result) noexcept;
        HRESULT __stdcall LockServer(BOOL) noexcept;
    };
}
