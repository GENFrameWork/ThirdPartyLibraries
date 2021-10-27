/*
Module : Toast++.h
Purpose: Defines the interface for a set of C++ classes which provide an encapsulation for Toast 
         Notifications from Desktop Win32 applications
History: PJN / 03-06-2017 1. Initial public release
         PJN / 24-06-2017 1. Provision of a number of new classes which provide a C++ object based way 
                          of creating the XML for toast notifications instead of having to specify XML 
                          text directly. This functionality is based on the UWP Community Toolkit
                          Notifications package. Currently these classes uses MSXML6 rather than the UWP 
                          XML parser as I was unable to get the UWP parser to operate correctly. If you 
                          know how to fix this, please let me know and I will look into reworking the code.
         PJN / 02-12-2018 1. Updated copyright details
                          2. Fixed a number of C++ core guidelines compiler warnings. These changes mean
                          that the code will now only compile on VC 2017 or later.
                          3. Updated the sample app to compile against the Windows 10.0.11763.0 SDK which 
                          eliminates various VS compiler errors when the code is compiled against earlier
                          versions of the Windows 10 SDK.
                          4. Changed all enum values to enum class
         PJN / 22-04-2019 1. Updated copyright details
                          2. Updated the code to clean compile on VC 2019

Copyright (c) 2017 - 2019 by PJ Naughter (Web: www.naughter.com, Email: pjna@naughter.com)

All rights reserved.

Copyright / Usage Details:

You are allowed to include the source code in any product (commercial, shareware, freeware or otherwise) 
when your product is released in binary form. You are allowed to modify the source code in any way you want 
except you cannot modify the copyright details at the top of each module. If you want to distribute source 
code with your application, then you are only allowed to distribute versions released by the author. This is 
to maintain a single distribution point for the source code. 

*/


////////////////////////// Macros / Defines ///////////////////////////////////

#pragma once

#ifndef __TOASTPP_H__
#define __TOASTPP_H__


////////////////////////// Includes ///////////////////////////////////////////

#ifndef __ATLPATH_H__
#pragma message("To avoid this message, please put atlpath.h in your pre compiled header (normally stdafx.h)")
#include <atlpath.h>
#endif //#ifndef __ATLPATH_H__

#ifndef __ATLSTR_H__
#pragma message("To avoid this message, please put atlstr.h in your pre compiled header (normally stdafx.h)")
#include <atlstr.h>
#endif //#ifndef __ATLSTR_H__

#ifndef _SHLOBJ_H_
#pragma message("To avoid this message, please put Shlobj.h in your pre compiled header (normally stdafx.h)")
#include <Shlobj.h>
#endif //#ifndef _SHLOBJ_H_

#ifndef _INC_PROPKEY
#pragma message("To avoid this message, please put propkey.h in your pre compiled header (normally stdafx.h)")
#include <propkey.h>
#endif //#ifndef _INC_PROPKEY

#include <propvarutil.h>

#ifndef _WRL_EVENT_H_
#pragma message("To avoid this message, please put wrl\\event.h in your pre compiled header (normally stdafx.h)")
#include <wrl\event.h>
#endif //#ifndef _WRL_EVENT_H_

#include <windows.ui.notifications.h>

#ifndef _STRING_
#pragma message("To avoid this message, please put string in your pre compiled header (normally stdafx.h)")
#include <string>
#endif //#ifndef _STRING_

#ifndef _VECTOR_
#pragma message("To avoid this message, please put vector in your pre compiled header (normally stdafx.h)")
#include <vector>
#endif //#ifndef _VECTOR_

#include <MsXml6.h>

#ifndef _CSTDIO_
#pragma message("To avoid this message, please put cstdio in your pre compiled header (normally stdafx.h)")
#include <cstdio>
#endif //#ifndef _CSTDIO_


////////////////////////// Macros / Defines ///////////////////////////////////

#ifndef INIT_PKEY_AppUserModel_ToastActivatorCLSID
EXTERN_C const PROPERTYKEY DECLSPEC_SELECTANY PKEY_AppUserModel_ToastActivatorCLSID = { { 0x9F4C2855, 0x9F79, 0x4B39,{ 0xA8, 0xD0, 0xE1, 0xD4, 0x2D, 0xE1, 0xD5, 0xF3 } }, 26 };
#define INIT_PKEY_AppUserModel_ToastActivatorCLSID { { 0x9F4C2855, 0x9F79, 0x4B39, 0xA8, 0xD0, 0xE1, 0xD4, 0x2D, 0xE1, 0xD5, 0xF3 }, 26 }
#endif //#ifndef INIT_PKEY_AppUserModel_ToastActivatorCLSID

#pragma comment(lib, "runtimeobject.lib")


////////////////////////// Classes ////////////////////////////////////////////

namespace ToastPP
{

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::Windows::Data::Xml::Dom;
using namespace ABI::Windows::Foundation;
using namespace ABI::Windows::UI::Notifications;
using namespace ATL;
using namespace std;


//Enums
enum class TemplateType
{
  Generic             = 0,
  ToastText01         = 1,
  ToastImageAndText01 = 2,
  ToastText02         = 3,
  ToastImageAndText02 = 4,
  ToastText03         = 5,
  ToastImageAndText03 = 6,
  ToastText04         = 7,
  ToastImageAndText04 = 8
};

enum class Scenario
{
  Default      = 0,
  Alarm        = 1,
  Reminder     = 2,
  IncomingCall = 3
};

enum class Duration
{
  Default = 0,
  Short   = 1,
  Long    = 2
};

enum class ImageCrop
{
  Default = 0,
  None    = 1,
  Circle  = 2
};

enum class ImagePlacement
{
  Default = 0,
  Inline  = 1,
};

enum class AdaptiveImageAlign
{
  Default = 0,
  Stretch = 1,
  Left    = 2,
  Center  = 3,
  Right   = 4
};

enum class AdaptiveImageCrop
{
  Default = 0,
  None    = 1,
  Circle  = 2
};

enum class SubgroupTextStacking
{
  Default = 0,
  Top     = 1,
  Center  = 2,
  Bottom  = 3
};

enum class AdaptiveTextAlign
{
  Default = 0,
  Auto    = 1,
  Left    = 2,
  Center  = 3,
  Right   = 4
};

enum class AdaptiveTextStyle
{
  Default          = 0,
  Caption          = 1,
  CaptionSubtle    = 2,
  Body             = 3,
  BodySubtle       = 4,
  Base             = 5,
  BaseSubtle       = 6,
  Subtitle         = 7,
  SubtitleSubtle   = 8,
  Title            = 9,
  TitleSubtle      = 10,
  TitleNumeral     = 11,
  Subheader        = 12,
  SubheaderSubtle  = 13,
  SubheaderNumeral = 14,
  Header           = 15,
  HeaderSubtle     = 16,
  HeaderNumeral    = 17
};


//Functions
static inline HRESULT AddAttribute(_In_ CComPtr<IXMLDOMNode> node, _In_z_ LPCWSTR pszAttribute, _In_z_ LPCWSTR pszValue)
{
  CComBSTR bstrAttribute(pszAttribute);
  CComBSTR bstrAttributeValue(pszValue);
  CComPtr<IXMLDOMElement> element;
  const HRESULT hr = node->QueryInterface(&element);
  if (FAILED(hr))
    return hr;
#pragma warning(suppress: 26486)
  CComVariant varValue(bstrAttributeValue);
  return element->setAttribute(bstrAttribute, varValue);
}

static inline HRESULT AddTextNode(_In_ const CComPtr<IXMLDOMDocument>& xml, _In_ const CComPtr<IXMLDOMNode>& parentNode, _In_z_ LPCWSTR pszId, _In_ const wstring& sValue)
{
  //Validate our parameters
  ASSERT(sValue.length() != 0);

  //What will be the return value from this method
  HRESULT hr = S_OK;

  //Create the "text" node
  CComPtr<IXMLDOMNode> textNode;
  CComBSTR bstrText(L"text");
  CComVariant varType(NODE_ELEMENT);
  CComBSTR bstrNS(L"");
  hr = xml->createNode(varType, bstrText, bstrNS, &textNode);
  if (FAILED(hr))
    return hr;

  //Create the id attribute
  hr = AddAttribute(textNode, L"id", pszId);
  if (FAILED(hr))
    return hr;

  //Set the value
  CComBSTR bstrTextValue(sValue.c_str());
  hr = textNode->put_text(bstrTextValue);
  if (FAILED(hr))
    return hr;

  //Finally update the DOM
  CComPtr<IXMLDOMNode> newChild;
  return parentNode->appendChild(textNode, &newChild);
}

static inline HRESULT AddImageNode(_In_ const CComPtr<IXMLDOMDocument>& xml, _In_ const CComPtr<IXMLDOMNode>& parentNode, _In_ const wstring& sSrc, _In_opt_z_ LPCWSTR pszAlternateText = nullptr)
{
  //Validate our parameters
#pragma warning(suppress: 26477)
  ATLASSERT(sSrc.length());

  //What will be the return value from this method
  HRESULT hr = S_OK;

  //Create the "image" node
  CComPtr<IXMLDOMNode> imageNode;
  CComBSTR bstrText(L"image");
  CComVariant varType(NODE_ELEMENT);
  CComBSTR bstrNS(L"");
  hr = xml->createNode(varType, bstrText, bstrNS, &imageNode);
  if (FAILED(hr))
    return hr;

  //Create the id attribute
  hr = AddAttribute(imageNode, L"id", L"1");
  if (FAILED(hr))
    return hr;

  //Create the src attribute
  hr = AddAttribute(imageNode, L"src", sSrc.c_str());
  if (FAILED(hr))
    return hr;

  //Create the alt attribute
  if (pszAlternateText != nullptr)
  {
    hr = AddAttribute(imageNode, L"alt", pszAlternateText);
    if (FAILED(hr))
      return hr;
  }

  //Finally update the DOM
  CComPtr<IXMLDOMNode> newChild;
  return parentNode->appendChild(imageNode, &newChild);
}


//Classes

class IGenericChild
{
public:
//Methods
  virtual HRESULT GetContent(_In_ CComPtr<IXMLDOMDocument>& /*xml*/, _In_ CComPtr<IXMLDOMNode>& /*parentNode*/) = 0;
};


class IWin81Child
{
public:
  //Methods
  virtual HRESULT GetContent(_In_ CComPtr<IXMLDOMDocument>& /*xml*/, _In_ CComPtr<IXMLDOMNode>& /*parentNode*/, _In_ TemplateType /*type*/) = 0;
};


class IText
{
public:
//Member variables
  wstring m_sText;
  wstring m_sLanguage;
};


class CGenericText : public IText, public IGenericChild
{
public:
//Constructors / Destructors
  CGenericText() = default;
  CGenericText(_In_ const wstring& sText)
  {
    m_sText = sText;
  }
  CGenericText(_In_ const wstring& sText, _In_ const wstring& sLanguage)
  {
    m_sText = sText;
    m_sLanguage = sLanguage;
  }
  CGenericText(const CGenericText&) = delete;
  CGenericText(CGenericText&&) = delete;
  virtual ~CGenericText() = default;

//Methods
  CGenericText& operator=(const CGenericText&) = delete;
  CGenericText& operator=(CGenericText&&) = delete;

  HRESULT GetContent(_In_ CComPtr<IXMLDOMDocument>& xml, _In_ CComPtr<IXMLDOMNode>& parentNode) override
  {
    //Create the "text" node
    CComPtr<IXMLDOMNode> textNode;
    CComBSTR bstrText(L"text");
    CComVariant varType(NODE_ELEMENT);
    CComBSTR bstrNS(L"");
    HRESULT hr = xml->createNode(varType, bstrText, bstrNS, &textNode);
    if (FAILED(hr))
      return hr;
    CComBSTR bstrTextValue(m_sText.c_str());
    hr = textNode->put_text(bstrTextValue);
    if (FAILED(hr))
      return hr;

    //Create the lang attribute
    if (m_sLanguage.length() != 0)
    {
      hr = AddAttribute(textNode, L"lang", m_sLanguage.c_str());
      if (FAILED(hr))
        return hr;
    }

    //Finally update the DOM
    CComPtr<IXMLDOMNode> newChild;
    return parentNode->appendChild(textNode, &newChild);
  }
};


class CAttributionText : public IText, public IGenericChild
{
public:
//Constructors / Destructors
  CAttributionText() = default;
  CAttributionText(_In_z_ LPCWSTR pszText)
  {
    m_sText = pszText;
  }
  CAttributionText(_In_z_ LPCWSTR pszText, _In_z_ LPCWSTR pszLanguage)
  {
    m_sText = pszText;
    m_sLanguage = pszLanguage;
  }
  CAttributionText(const CAttributionText&) = delete;
  CAttributionText(CAttributionText&&) = delete;
  virtual ~CAttributionText() = default;

//Methods
  CAttributionText& operator=(const CAttributionText&) = delete;
  CAttributionText& operator=(CAttributionText&&) = delete;

  HRESULT GetContent(_In_ CComPtr<IXMLDOMDocument>& xml, _In_ CComPtr<IXMLDOMNode>& parentNode) override
  {
    if (m_sText.length() == 0)
      return S_FALSE;

    //Create the "text" node
    CComPtr<IXMLDOMNode> textNode;
    CComBSTR bstrText(L"text");
    CComVariant varType(NODE_ELEMENT);
    CComBSTR bstrNS(L"");
    HRESULT hr = xml->createNode(varType, bstrText, bstrNS, &textNode);
    if (FAILED(hr))
      return hr;
    CComBSTR bstrTextValue(m_sText.c_str());
    hr = textNode->put_text(bstrTextValue);
    if (FAILED(hr))
      return hr;

    //Create the placement attribute
    hr = AddAttribute(textNode, L"placement", L"attribution");
    if (FAILED(hr))
      return hr;

    //Finally update the DOM
    CComPtr<IXMLDOMNode> newChild;
    return parentNode->appendChild(textNode, &newChild);
  }
};


class IAdaptiveChild
{
};


class IAdaptiveSubgroupChild : public IGenericChild
{
};


class CAdaptiveText : public IAdaptiveChild, public IAdaptiveSubgroupChild
{
public:
//Constructors / Destructors
  CAdaptiveText() noexcept : m_HintStyle(AdaptiveTextStyle::Default),
                             m_bHintWrap(false),
                             m_nHintMaxLines(-1),
                             m_nHintMinLines(-1),
                             m_HintAlign(AdaptiveTextAlign::Default)
  {
  }
  CAdaptiveText(_In_z_ LPCWSTR pszText) : m_sText(pszText),
                                          m_HintStyle(AdaptiveTextStyle::Default),
                                          m_bHintWrap(false),
                                          m_nHintMaxLines(-1),
                                          m_nHintMinLines(-1),
                                          m_HintAlign(AdaptiveTextAlign::Default)
  {
  }
  CAdaptiveText(_In_z_ LPCWSTR pszText, _In_z_ LPCWSTR pszLanguage) : m_sText(pszText),
                                                                      m_sLanguage(pszLanguage),
                                                                      m_HintStyle(AdaptiveTextStyle::Default),
                                                                      m_bHintWrap(false),
                                                                      m_nHintMaxLines(-1),
                                                                      m_nHintMinLines(-1),
                                                                      m_HintAlign(AdaptiveTextAlign::Default)
  {
  }
  CAdaptiveText(const CAdaptiveText&) = delete;
  CAdaptiveText(CAdaptiveText&&) = delete;
  virtual ~CAdaptiveText() = default;

//Methods
  CAdaptiveText& operator=(const CAdaptiveText&) = delete;
  CAdaptiveText& operator=(CAdaptiveText&&) = delete;

  HRESULT GetContent(_In_ CComPtr<IXMLDOMDocument>& xml, _In_ CComPtr<IXMLDOMNode>& parentNode) override
  {
    //Create the "text" node
    CComPtr<IXMLDOMNode> textNode;
    CComBSTR bstrText(L"text");
    CComVariant varType(NODE_ELEMENT);
    CComBSTR bstrNS(L"");
    HRESULT hr = xml->createNode(varType, bstrText, bstrNS, &textNode);
    if (FAILED(hr))
      return hr;
    CComBSTR bstrTextValue(m_sText.c_str());
    hr = textNode->put_text(bstrTextValue);
    if (FAILED(hr))
      return hr;

    //Create the hint-style attribute
    if (m_HintStyle != AdaptiveTextStyle::Default)
    {
      switch (m_HintStyle)
      {
        case AdaptiveTextStyle::Caption:
        {
          hr = AddAttribute(textNode, L"hint-style", L"caption");
          break;
        }
        case AdaptiveTextStyle::CaptionSubtle:
        {
          hr = AddAttribute(textNode, L"hint-style", L"captionSubtle");
          break;
        }
        case AdaptiveTextStyle::Body:
        {
          hr = AddAttribute(textNode, L"hint-style", L"body");
          break;
        }
        case AdaptiveTextStyle::BodySubtle:
        {
          hr = AddAttribute(textNode, L"hint-style", L"bodySubtle");
          break;
        }
        case AdaptiveTextStyle::Base:
        {
          hr = AddAttribute(textNode, L"hint-style", L"base");
          break;
        }
        case AdaptiveTextStyle::BaseSubtle:
        {
          hr = AddAttribute(textNode, L"hint-style", L"baseSubtle");
          break;
        }
        case AdaptiveTextStyle::Subtitle:
        {
          hr = AddAttribute(textNode, L"hint-style", L"subtitle");
          break;
        }
        case AdaptiveTextStyle::SubtitleSubtle:
        {
          hr = AddAttribute(textNode, L"hint-style", L"subtitleSubtle");
          break;
        }
        case AdaptiveTextStyle::Title:
        {
          hr = AddAttribute(textNode, L"hint-style", L"title");
          break;
        }
        case AdaptiveTextStyle::TitleSubtle:
        {
          hr = AddAttribute(textNode, L"hint-style", L"titleSubtle");
          break;
        }
        case AdaptiveTextStyle::TitleNumeral:
        {
          hr = AddAttribute(textNode, L"hint-style", L"titleNumeral");
          break;
        }
        case AdaptiveTextStyle::Subheader:
        {
          hr = AddAttribute(textNode, L"hint-style", L"subheader");
          break;
        }
        case AdaptiveTextStyle::SubheaderSubtle:
        {
          hr = AddAttribute(textNode, L"hint-style", L"subheaderSubtle");
          break;
        }
        case AdaptiveTextStyle::SubheaderNumeral:
        {
          hr = AddAttribute(textNode, L"hint-style", L"subheaderNumeral");
          break;
        }
        case AdaptiveTextStyle::Header:
        {
          hr = AddAttribute(textNode, L"hint-style", L"header");
          break;
        }
        case AdaptiveTextStyle::HeaderSubtle:
        {
          hr = AddAttribute(textNode, L"hint-style", L"headerSubtle");
          break;
        }
        case AdaptiveTextStyle::HeaderNumeral:
        {
          hr = AddAttribute(textNode, L"hint-style", L"headerNumeral");
          break;
        }
        default:
        {
#pragma warning(suppress: 26477)
          ATLASSERT(FALSE);
          break;
        }
      }
      if (FAILED(hr))
        return hr;
    }

    //Create the hintWrap attribute
    if (m_bHintWrap)
    {
      hr = AddAttribute(textNode, L"HintWrap", L"true");
      if (FAILED(hr))
        return hr;
    }

    //Create the hint-maxLines attribute
    if (m_nHintMaxLines != -1)
    {
      CAtlStringW sMaxLines;
      sMaxLines.Format(L"%d", m_nHintMaxLines);
      hr = AddAttribute(textNode, L"hint-maxLines", sMaxLines);
      if (FAILED(hr))
        return hr;
    }

    //Create the hint-minLines attribute
    if (m_nHintMinLines != -1)
    {
      CAtlStringW sMinLines;
      sMinLines.Format(L"%d", m_nHintMinLines);
      hr = AddAttribute(textNode, L"hint-minLines", sMinLines);
      if (FAILED(hr))
        return hr;
    }

    //Create the hint-align attribute
    if (m_HintAlign != AdaptiveTextAlign::Default)
    {
      switch (m_HintAlign)
      {
        case AdaptiveTextAlign::Auto:
        {
          hr = AddAttribute(textNode, L"hint-align", L"auto");
          break;
        }
        case AdaptiveTextAlign::Left:
        {
          hr = AddAttribute(textNode, L"hint-align", L"left");
          break;
        }
        case AdaptiveTextAlign::Center:
        {
          hr = AddAttribute(textNode, L"hint-align", L"center");
          break;
        }
        case AdaptiveTextAlign::Right:
        {
          hr = AddAttribute(textNode, L"hint-align", L"right");
          break;
        }
        default:
        {
#pragma warning(suppress: 26477)
          ATLASSERT(FALSE);
          break;
        }
      }
      if (FAILED(hr))
        return hr;
    }

    //Create the lang attribute
    if (m_sLanguage.length() != 0)
    {
      hr = AddAttribute(textNode, L"lang", m_sLanguage.c_str());
      if (FAILED(hr))
        return hr;
    }

    //Finally update the DOM
    CComPtr<IXMLDOMNode> newChild;
    return parentNode->appendChild(textNode, &newChild);
  }

//Member variables
  wstring           m_sText;
  AdaptiveTextStyle m_HintStyle;
  bool              m_bHintWrap;
  int               m_nHintMaxLines;
  int               m_nHintMinLines;
  AdaptiveTextAlign m_HintAlign;
  wstring           m_sLanguage;
};


class IImageWin81
{
public:
//Member variables
  wstring m_sSource;
  wstring m_sAlternateText;
};


class IGenericImage
{
public:
//Constructors / Destructors
  IGenericImage() noexcept : m_bAddImageQuery(false)
  {
  }

//Member variables
  wstring m_sSource;
  wstring m_sAlternateText;
  bool    m_bAddImageQuery;
};


class CGenericImage : public IGenericImage, public IGenericChild
{
public:
//Constructors / Destructors
  CGenericImage() noexcept : m_Placement(ImagePlacement::Default),
                             m_HintCrop(ImageCrop::Default)
  {
  }
  CGenericImage(_In_z_ LPCWSTR pszSource, _In_ ImagePlacement placement = ImagePlacement::Default,
                _In_ ImageCrop imageCrop = ImageCrop::Default, _In_ bool bAddImageQuery = false) : m_Placement(placement),
                                                                                                   m_HintCrop(imageCrop)
  {
    m_sSource = pszSource;
    m_bAddImageQuery = bAddImageQuery;
  }
  CGenericImage(_In_z_ LPCWSTR pszSource, _In_z_ LPCWSTR pszAlternateText, _In_ ImagePlacement placement = ImagePlacement::Default,
                _In_ ImageCrop imageCrop = ImageCrop::Default, _In_ bool bAddImageQuery = false) : m_Placement(placement),
                                                                                                   m_HintCrop(imageCrop)
  {
    m_sSource = pszSource;
    m_sAlternateText = pszAlternateText;
    m_bAddImageQuery = bAddImageQuery;
  }
  CGenericImage(const CGenericImage&) = delete;
  CGenericImage(CGenericImage&&) = delete;
  virtual ~CGenericImage() = default;

//Methods
  CGenericImage& operator=(const CGenericImage&) = delete;
  CGenericImage& operator=(CGenericImage&&) = delete;

  HRESULT GetContent(_In_ CComPtr<IXMLDOMDocument>& xml, _In_ CComPtr<IXMLDOMNode>& parentNode) override
  {
    //Create the "image" node
    CComPtr<IXMLDOMNode> imageNode;
    CComBSTR bstrImage(L"image");
    CComVariant varType(NODE_ELEMENT);
    CComBSTR bstrNS(L"");
    HRESULT hr = xml->createNode(varType, bstrImage, bstrNS, &imageNode);
    if (FAILED(hr))
      return hr;

    //Create the src attribute
    hr = AddAttribute(imageNode, L"src", m_sSource.c_str());
    if (FAILED(hr))
      return hr;

    //Create the placement attribute
    if (m_Placement != ImagePlacement::Default)
    {
      switch (m_Placement)
      {
        case ImagePlacement::Inline:
        {
          hr = AddAttribute(imageNode, L"placement", L"inline");
          break;
        }
        default:
        {
#pragma warning(suppress: 26477)
          ATLASSERT(FALSE);
          break;
        }
      }
      if (FAILED(hr))
        return hr;
    }

    //Create the alt attribute
    if (m_sAlternateText.length() != 0)
    {
      hr = AddAttribute(imageNode, L"alt", m_sAlternateText.c_str());
      if (FAILED(hr))
        return hr;
    }

    //Create the addImageQuery attribute
    if (m_bAddImageQuery)
    {
      hr = AddAttribute(imageNode, L"addImageQuery", L"true");
      if (FAILED(hr))
        return hr;
    }

    //Create the hint-crop attribute
    if (m_HintCrop != ImageCrop::Default)
    {
      switch (m_HintCrop)
      {
        case ImageCrop::None:
        {
          hr = AddAttribute(imageNode, L"hint-crop", L"none");
          break;
        }
        case ImageCrop::Circle:
        {
          hr = AddAttribute(imageNode, L"hint-crop", L"circle");
          break;
        }
        default:
        {
#pragma warning(suppress: 26477)
          ATLASSERT(FALSE);
          break;
        }
      }
      if (FAILED(hr))
        return hr;
    }

    //Finally update the DOM
    CComPtr<IXMLDOMNode> newChild;
    return parentNode->appendChild(imageNode, &newChild);
  }

//Member variables
  ImagePlacement m_Placement;
  ImageCrop      m_HintCrop;
};


class CAppLogo : public IGenericImage, public IGenericChild
{
public:
//Constructors / Destructors
  CAppLogo() noexcept : m_HintCrop(ImageCrop::Default)
  {
  }
  CAppLogo(_In_z_ LPCWSTR pszSource, _In_ ImageCrop imageCrop = ImageCrop::Default, _In_ bool bAddImageQuery = false) : m_HintCrop(imageCrop)
  {
    m_sSource = pszSource;
    m_bAddImageQuery = bAddImageQuery;
  }
  CAppLogo(_In_z_ LPCWSTR pszSource, _In_z_ LPCWSTR pszAlternateText, _In_ ImageCrop imageCrop = ImageCrop::Default, _In_ bool bAddImageQuery = false) : m_HintCrop(imageCrop)
  {
    m_sSource = pszSource;
    m_sAlternateText = pszAlternateText;
    m_bAddImageQuery = bAddImageQuery;
  }
  CAppLogo(const CAppLogo&) = delete;
  CAppLogo(CAppLogo&&) = delete;
  virtual ~CAppLogo() = default;

//Methods
  CAppLogo& operator=(const CAppLogo&) = delete;
  CAppLogo& operator=(CAppLogo&&) = delete;

  HRESULT GetContent(_In_ CComPtr<IXMLDOMDocument>& xml, _In_ CComPtr<IXMLDOMNode>& parentNode) override
  {
    if (m_sSource.length() == 0)
      return S_FALSE;

    //Create the "image" node
    CComPtr<IXMLDOMNode> imageNode;
    CComBSTR bstrImage(L"image");
    CComVariant varType(NODE_ELEMENT);
    CComBSTR bstrNS(L"");
    HRESULT hr = xml->createNode(varType, bstrImage, bstrNS, &imageNode);
    if (FAILED(hr))
      return hr;

    //Create the src attribute
    hr = AddAttribute(imageNode, L"src", m_sSource.c_str());
    if (FAILED(hr))
      return hr;

    //Create the placement attribute
    hr = AddAttribute(imageNode, L"placement", L"appLogoOverride");
    if (FAILED(hr))
      return hr;

    //Create the alt attribute
    if (m_sAlternateText.length() != 0)
    {
      hr = AddAttribute(imageNode, L"alt", m_sAlternateText.c_str());
      if (FAILED(hr))
        return hr;
    }

    //Create the addImageQuery attribute
    if (m_bAddImageQuery)
    {
      hr = AddAttribute(imageNode, L"addImageQuery", L"true");
      if (FAILED(hr))
        return hr;
    }

    //Create the hint-crop attribute
    if (m_HintCrop != ImageCrop::Default)
    {
      switch (m_HintCrop)
      {
        case ImageCrop::None:
        {
          hr = AddAttribute(imageNode, L"hint-crop", L"none");
          break;
        }
        case ImageCrop::Circle:
        {
          hr = AddAttribute(imageNode, L"hint-crop", L"circle");
          break;
        }
        default:
        {
#pragma warning(suppress: 26477)
          ATLASSERT(FALSE);
          break;
        }
      }
      if (FAILED(hr))
        return hr;
    }

    //Finally update the DOM
    CComPtr<IXMLDOMNode> newChild;
    return parentNode->appendChild(imageNode, &newChild);
  }

//Member variables
  ImageCrop m_HintCrop;
};


class CHeroImage : public IGenericImage, public IGenericChild
{
public:
//Constructors / Destructors
  CHeroImage() = default;
  CHeroImage(_In_z_ LPCWSTR pszSource, _In_ bool bAddImageQuery = false)
  {
    m_sSource = pszSource;
    m_bAddImageQuery = bAddImageQuery;
  }
  CHeroImage(_In_z_ LPCWSTR pszSource, _In_z_ LPCWSTR pszAlternateText, _In_ bool bAddImageQuery = false)
  {
    m_sSource = pszSource;
    m_sAlternateText = pszAlternateText;
    m_bAddImageQuery = bAddImageQuery;
  }
  CHeroImage(const CHeroImage&) = delete;
  CHeroImage(CHeroImage&&) = delete;
  virtual ~CHeroImage() = default;

//Methods
  CHeroImage& operator=(const CHeroImage&) = delete;
  CHeroImage& operator=(CHeroImage&&) = delete;

  HRESULT GetContent(_In_ CComPtr<IXMLDOMDocument>& xml, _In_ CComPtr<IXMLDOMNode>& parentNode) override
  {
    if (m_sSource.length() == 0)
      return S_FALSE;

    //Create the "image" node
    CComPtr<IXMLDOMNode> imageNode;
    CComBSTR bstrImage(L"image");
    CComVariant varType(NODE_ELEMENT);
    CComBSTR bstrNS(L"");
    HRESULT hr = xml->createNode(varType, bstrImage, bstrNS, &imageNode);
    if (FAILED(hr))
      return hr;

    //Create the src attribute
    hr = AddAttribute(imageNode, L"src", m_sSource.c_str());
    if (FAILED(hr))
      return hr;

    //Create the placement attribute
    hr = AddAttribute(imageNode, L"placement", L"hero");
    if (FAILED(hr))
      return hr;

    //Create the alt attribute
    if (m_sAlternateText.length() != 0)
    {
      hr = AddAttribute(imageNode, L"alt", m_sAlternateText.c_str());
      if (FAILED(hr))
        return hr;
    }

    //Create the addImageQuery attribute
    if (m_bAddImageQuery)
    {
      hr = AddAttribute(imageNode, L"addImageQuery", L"true");
      if (FAILED(hr))
        return hr;
    }

    //Finally update the DOM
    CComPtr<IXMLDOMNode> newChild;
    return parentNode->appendChild(imageNode, &newChild);
  }
};


class CAdaptiveImage : public IAdaptiveChild, public IAdaptiveSubgroupChild, public IGenericImage
{
public:
//Constructors / Destructors
  CAdaptiveImage() noexcept : m_HintCrop(AdaptiveImageCrop::Default),
                              m_bHintRemoveMargin(false),
                              m_HintAlign(AdaptiveImageAlign::Default)
  {
  }
  CAdaptiveImage(_In_z_ LPCWSTR pszSource, _In_ AdaptiveImageCrop hintCrop = AdaptiveImageCrop::Default,
                 _In_ AdaptiveImageAlign hintAlign = AdaptiveImageAlign::Default,
                 _In_ bool bAddImageQuery = false, _In_ bool bHintRemoveMargin = false) : m_HintCrop(hintCrop),
                                                                                          m_HintAlign(hintAlign),
                                                                                          m_bHintRemoveMargin(bHintRemoveMargin)
  {
    m_sSource = pszSource;
    m_bAddImageQuery = bAddImageQuery;
  }
  CAdaptiveImage(_In_z_ LPCWSTR pszSource, _In_z_ LPCWSTR pszAlternateText,
                 _In_ AdaptiveImageCrop hintCrop = AdaptiveImageCrop::Default,
                 _In_ AdaptiveImageAlign hintAlign = AdaptiveImageAlign::Default,
                 _In_ bool bAddImageQuery = false, _In_ bool bHintRemoveMargin = false) : m_HintCrop(hintCrop),
                                                                                          m_HintAlign(hintAlign),
                                                                                          m_bHintRemoveMargin(bHintRemoveMargin)
  {
    m_sSource = pszSource;
    m_sAlternateText = pszAlternateText;
    m_bAddImageQuery = bAddImageQuery;
  }
  CAdaptiveImage(const CAdaptiveImage&) = delete;
  CAdaptiveImage(CAdaptiveImage&&) = delete;
  virtual ~CAdaptiveImage() = default;

//Methods
  CAdaptiveImage& operator=(const CAdaptiveImage&) = delete;
  CAdaptiveImage& operator=(CAdaptiveImage&&) = delete;

  HRESULT GetContent(_In_ CComPtr<IXMLDOMDocument>& xml, _In_ CComPtr<IXMLDOMNode>& parentNode) override
  {
    //Create the "image" node
    CComPtr<IXMLDOMNode> imageNode;
    CComBSTR bstrImage(L"image");
    CComVariant varType(NODE_ELEMENT);
    CComBSTR bstrNS(L"");
    HRESULT hr = xml->createNode(varType, bstrImage, bstrNS, &imageNode);
    if (FAILED(hr))
      return hr;

    //Create the src attribute
    hr = AddAttribute(imageNode, L"src", m_sSource.c_str());
    if (FAILED(hr))
      return hr;

    //Create the alt attribute
    if (m_sAlternateText.length() != 0)
    {
      hr = AddAttribute(imageNode, L"alt", m_sAlternateText.c_str());
      if (FAILED(hr))
        return hr;
    }

    //Create the addImageQuery attribute
    if (m_bAddImageQuery)
    {
      hr = AddAttribute(imageNode, L"addImageQuery", L"true");
      if (FAILED(hr))
        return hr;
    }

    //Create the hint-crop attribute
    if (m_HintCrop != AdaptiveImageCrop::Default)
    {
      switch (m_HintCrop)
      {
        case AdaptiveImageCrop::None:
        {
          hr = AddAttribute(imageNode, L"hint-crop", L"none");
          break;
        }
        case AdaptiveImageCrop::Circle:
        {
          hr = AddAttribute(imageNode, L"hint-crop", L"circle");
          break;
        }
        default:
        {
#pragma warning(suppress: 26477)
          ATLASSERT(FALSE);
          break;
        }
      }
      if (FAILED(hr))
        return hr;
    }

    //Create the hint-removeMargin attribute
    if (m_bHintRemoveMargin)
    {
      hr = AddAttribute(imageNode, L"hint-removeMargin", L"true");
      if (FAILED(hr))
        return hr;
    }

    //Create the hint-align attribute
    if (m_HintAlign != AdaptiveImageAlign::Default)
    {
      switch (m_HintAlign)
      {
        case AdaptiveImageAlign::Stretch:
        {
          hr = AddAttribute(imageNode, L"hint-align", L"stretch");
          break;
        }
        case AdaptiveImageAlign::Left:
        {
          hr = AddAttribute(imageNode, L"hint-align", L"left");
          break;
        }
        case AdaptiveImageAlign::Center:
        {
          hr = AddAttribute(imageNode, L"hint-align", L"center");
          break;
        }
        case AdaptiveImageAlign::Right:
        {
          hr = AddAttribute(imageNode, L"hint-align", L"right");
          break;
        }
        default:
        {
#pragma warning(suppress: 26477)
          ATLASSERT(FALSE);
          break;
        }
      }
      if (FAILED(hr))
        return hr;
    }

    //Finally update the DOM
    CComPtr<IXMLDOMNode> newChild;
    return parentNode->appendChild(imageNode, &newChild);
  }

  //Member variables
  AdaptiveImageCrop  m_HintCrop;
  bool               m_bHintRemoveMargin;
  AdaptiveImageAlign m_HintAlign;
};


class CProgressBar : public IGenericChild
{
public:
//Constructors / Destructors
  CProgressBar() = default;
  CProgressBar(const CProgressBar&) = delete;
  CProgressBar(CProgressBar&&) = delete;
  virtual ~CProgressBar() = default;

//Methods
  CProgressBar& operator=(const CProgressBar&) = delete;
  CProgressBar& operator=(CProgressBar&&) = delete;

  HRESULT GetContent(_In_ CComPtr<IXMLDOMDocument>& xml, _In_ CComPtr<IXMLDOMNode>& parentNode) override
  {
    //Create the "progress" node
    CComPtr<IXMLDOMNode> progressNode;
    CComBSTR bstrProgress(L"progress");
    CComVariant varType(NODE_ELEMENT);
    CComBSTR bstrNS(L"");
    HRESULT hr = xml->createNode(varType, bstrProgress, bstrNS, &progressNode);
    if (FAILED(hr))
      return hr;

    //Create the title attribute
    if (m_sTitle.length() != 0)
    {
      hr = AddAttribute(progressNode, L"title", m_sTitle.c_str());
      if (FAILED(hr))
        return hr;
    }

    //Create the status attribute
    hr = AddAttribute(progressNode, L"status", m_sStatus.c_str());
    if (FAILED(hr))
      return hr;

    //Create the "value" attribute
    hr = AddAttribute(progressNode, L"value", m_sValue.c_str());
    if (FAILED(hr))
      return hr;

    //Create the valueStringOverride attribute
    if (m_sValueStringOverride.length() != 0)
    {
      hr = AddAttribute(progressNode, L"valueStringOverride", m_sValueStringOverride.c_str());
      if (FAILED(hr))
        return hr;
    }

    //Finally update the DOM
    CComPtr<IXMLDOMNode> newChild;
    return parentNode->appendChild(progressNode, &newChild);
  }

//Member variables
  wstring m_sTitle;
  wstring m_sStatus;
  wstring m_sValue;
  wstring m_sValueStringOverride;
};


class CWin81Binding : public IWin81Child
{
public:
//Constructors / Destructors
  CWin81Binding() = default;
  CWin81Binding(const CWin81Binding&) = delete;
  CWin81Binding(CWin81Binding&&) = delete;
  virtual ~CWin81Binding() = default;

//Methods
  CWin81Binding& operator=(const CWin81Binding&) = delete;
  CWin81Binding& operator=(CWin81Binding&&) = delete;

  HRESULT GetContent(_In_ CComPtr<IXMLDOMDocument>& xml, _In_ CComPtr<IXMLDOMNode>& parentNode, _In_ TemplateType type) override
  {
    //Create the "binding" node
    CComPtr<IXMLDOMNode> bindingNode;
    CComBSTR bstrBinding(L"binding");
    CComVariant varType(NODE_ELEMENT);
    CComBSTR bstrNS(L"");
    HRESULT hr = xml->createNode(varType, bstrBinding, bstrNS, &bindingNode);
    if (FAILED(hr))
      return hr;

    //Handle "template" attribute
    switch (type)
    {
      case TemplateType::ToastText01:
      {
        hr = AddAttribute(bindingNode, L"template", L"ToastText01");
        break;
      }
      case TemplateType::ToastImageAndText01:
      {
        hr = AddAttribute(bindingNode, L"template", L"ToastImageAndText01");
        break;
      }
      case TemplateType::ToastText02:
      {
        hr = AddAttribute(bindingNode, L"template", L"ToastText02");
        break;
      }
      case TemplateType::ToastImageAndText02:
      {
        hr = AddAttribute(bindingNode, L"template", L"ToastImageAndText02");
        break;
      }
      case TemplateType::ToastText03:
      {
        hr = AddAttribute(bindingNode, L"template", L"ToastText03");
        break;
      }
      case TemplateType::ToastImageAndText03:
      {
        hr = AddAttribute(bindingNode, L"template", L"ToastImageAndText03");
        break;
      }
      case TemplateType::ToastText04:
      {
        hr = AddAttribute(bindingNode, L"template", L"ToastText04");
        break;
      }
      case TemplateType::ToastImageAndText04:
      {
        hr = AddAttribute(bindingNode, L"template", L"ToastImageAndText04");
        break;
      }
      default:
      {
#pragma warning(suppress: 26477)
        ATLASSERT(FALSE);
        break;
      }
    }
    if (FAILED(hr))
      return hr;

    //Handle Image node
    if ((type == TemplateType::ToastImageAndText01) || (type == TemplateType::ToastImageAndText02) || (type == TemplateType::ToastImageAndText03) || (type == TemplateType::ToastImageAndText04))
    {
      hr = AddImageNode(xml, bindingNode, m_Image.m_sSource, m_Image.m_sAlternateText.length() ? m_Image.m_sAlternateText.c_str() : nullptr);
      if (FAILED(hr))
        return hr;
    }

    //Handle Text1 node
    hr = AddTextNode(xml, bindingNode, L"1", m_sText1);
    if (FAILED(hr))
      return hr;

    //Handle Text2 node
    if ((type != TemplateType::ToastText01) && (type != TemplateType::ToastImageAndText01))
    {
      hr = AddTextNode(xml, bindingNode, L"2", m_sText2);
      if (FAILED(hr))
        return hr;
    }

    //Handle Text3 node
    if ((type == TemplateType::ToastText04) || (type == TemplateType::ToastImageAndText04))
    {
      hr = AddTextNode(xml, bindingNode, L"3", m_sText3);
      if (FAILED(hr))
        return hr;
    }

    //Finally update the DOM
    CComPtr<IXMLDOMNode> newChild;
    return parentNode->appendChild(bindingNode, &newChild);
  }

  //Member variables
  IImageWin81 m_Image;
  wstring     m_sText1;
  wstring     m_sText2;
  wstring     m_sText3;
};


class CGenericBinding : public IGenericChild
{
public:
//Constructors / Destructors
  CGenericBinding() noexcept : m_bAddImageQuery(false)
  {
  }
  CGenericBinding(const CGenericBinding&) = delete;
  CGenericBinding(CGenericBinding&&) = delete;
  virtual ~CGenericBinding() = default;

//Methods
  CGenericBinding& operator=(const CGenericBinding&) = delete;
  CGenericBinding& operator=(CGenericBinding&&) = delete;

  HRESULT GetContent(_In_ CComPtr<IXMLDOMDocument>& xml, _In_ CComPtr<IXMLDOMNode>& parentNode) override
  {
    //Create the "binding" node
    CComPtr<IXMLDOMNode> bindingNode;
    CComBSTR bstrBinding(L"binding");
    CComVariant varType(NODE_ELEMENT);
    CComBSTR bstrNS(L"");
    HRESULT hr = xml->createNode(varType, bstrBinding, bstrNS, &bindingNode);
    if (FAILED(hr))
      return hr;

    //Handle the template attribute
    hr = AddAttribute(bindingNode, L"template", L"ToastGeneric");
    if (FAILED(hr))
      return hr;

    //Create the lang attribute
    if (m_sLanguage.length() != 0)
    {
      hr = AddAttribute(bindingNode, L"lang", m_sLanguage.c_str());
      if (FAILED(hr))
        return hr;
    }

    //Create the baseUri attribute
    if (m_sBaseUri.length() != 0)
    {
      hr = AddAttribute(bindingNode, L"baseUri", m_sBaseUri.c_str());
      if (FAILED(hr))
        return hr;
    }

    //Create the addImageQuery attribute
    if (m_bAddImageQuery)
    {
      hr = AddAttribute(bindingNode, L"addImageQuery", L"true");
      if (FAILED(hr))
        return hr;
    }

    //Handle the AppLogoOverride
    hr = m_AppLogoOverride.GetContent(xml, bindingNode);
    if (FAILED(hr))
      return hr;

    //Handle the HeroImage
    hr = m_HeroImage.GetContent(xml, bindingNode);
    if (FAILED(hr))
      return hr;

    //Handle the Attribution
    hr = m_Attribution.GetContent(xml, bindingNode);
    if (FAILED(hr))
      return hr;

    //Handle all the children
    for (auto& c : m_Children)
    {
      hr = c->GetContent(xml, bindingNode);
      if (FAILED(hr))
        return hr;
    }

    //Finally update the DOM
    CComPtr<IXMLDOMNode> newChild;
    return parentNode->appendChild(bindingNode, &newChild);
  }

//Member variables
  wstring                m_sLanguage;
  wstring                m_sBaseUri;
  bool                   m_bAddImageQuery;
  vector<IGenericChild*> m_Children;
  CAttributionText       m_Attribution;
  CAppLogo               m_AppLogoOverride;
  CHeroImage             m_HeroImage;
};


class CVisual : public IWin81Child
{
public:
//Constructors / Destructors
  CVisual() noexcept : m_bAddImageQuery(false)
  {
  }
  CVisual(const CVisual&) = delete;
  CVisual(CVisual&&) = delete;
  virtual ~CVisual() = default;

//Methods
  CVisual& operator=(const CVisual&) = delete;
  CVisual& operator= (CVisual&&) = delete;

  HRESULT GetContent(_In_ CComPtr<IXMLDOMDocument>& xml, _In_ CComPtr<IXMLDOMNode>& parentNode, _In_ TemplateType type) override
  {
    //Create the "visual" node
    CComPtr<IXMLDOMNode> visualNode;
    CComBSTR bstrVisual(L"visual");
    CComVariant varType(NODE_ELEMENT);
    CComBSTR bstrNS(L"");
    HRESULT hr = xml->createNode(varType, bstrVisual, bstrNS, &visualNode);
    if (FAILED(hr))
      return hr;

    //Create the Win81 binding if necessary
    if (type != TemplateType::Generic)
    {
      hr = m_BindingWin81.GetContent(xml, visualNode, type);
      if (FAILED(hr))
        return hr;
    
      //Finally update the DOM
      CComPtr<IXMLDOMNode> newChild;
      return parentNode->appendChild(visualNode, &newChild);
    }

    //Create the lang attribute
    if (m_sLanguage.length() != 0)
    {
      hr = AddAttribute(visualNode, L"lang", m_sLanguage.c_str());
      if (FAILED(hr))
        return hr;
    }

    //Create the baseUri attribute
    if (m_sBaseUri.length() != 0)
    {
      hr = AddAttribute(visualNode, L"baseUri", m_sBaseUri.c_str());
      if (FAILED(hr))
        return hr;
    }

    //Create the addImageQuery attribute
    if (m_bAddImageQuery)
    {
      hr = AddAttribute(visualNode, L"addImageQuery", L"true");
      if (FAILED(hr))
        return hr;
    }

    //Handle m_BindingGeneric
    hr = m_BindingGeneric.GetContent(xml, visualNode);
    if (FAILED(hr))
      return hr;

    //Finally update the DOM
    CComPtr<IXMLDOMNode> newChild;
    return parentNode->appendChild(visualNode, &newChild);
  }

//Member variables
  wstring         m_sLanguage;
  wstring         m_sBaseUri;
  bool            m_bAddImageQuery;
  CGenericBinding m_BindingGeneric;
  CWin81Binding   m_BindingWin81;
};


class CAudio : public IGenericChild
{
public:
//Constructors / Destructors
  CAudio() noexcept : m_bLoop(false),
                      m_bSilent(false)
  {
  }
  CAudio(const CAudio&) = delete;
  CAudio(CAudio&&) = delete;
  virtual ~CAudio() = default;

//Methods
  CAudio& operator=(const CAudio&) = delete;
  CAudio& operator=(CAudio&&) = delete;

  HRESULT GetContent(_In_ CComPtr<IXMLDOMDocument>& xml, _In_ CComPtr<IXMLDOMNode>& parentNode) override
  {
    if (m_sSrc.length() == 0)
      return S_FALSE;

    //Create the "visual" node
    CComPtr<IXMLDOMNode> audioNode;
    CComBSTR bstrAudio(L"audio");
    CComVariant varType(NODE_ELEMENT);
    CComBSTR bstrNS(L"");
    HRESULT hr = xml->createNode(varType, bstrAudio, bstrNS, &audioNode);
    if (FAILED(hr))
      return hr;

    //Create the src attribute
    hr = AddAttribute(audioNode, L"src", m_sSrc.c_str());
    if (FAILED(hr))
      return hr;

    //Create the loop attribute
    if (m_bLoop)
    {
      hr = AddAttribute(audioNode, L"loop", L"true");
      if (FAILED(hr))
        return hr;
    }

    //Create the silent attribute
    if (m_bSilent)
    {
      hr = AddAttribute(audioNode, L"silent", L"true");
      if (FAILED(hr))
        return hr;
    }

    //Finally update the DOM
    CComPtr<IXMLDOMNode> newChild;
    return parentNode->appendChild(audioNode, &newChild);
  }

//Member variables
  wstring m_sSrc;
  bool    m_bLoop;
  bool    m_bSilent;
};


class IContextMenuItem : public IGenericChild
{
};


class CContextMenuItem : public IContextMenuItem
{
public:
//Constructors / Destructors
  CContextMenuItem() = default;
  CContextMenuItem(_In_z_ LPCWSTR pszContent, _In_z_ LPCWSTR pszArguments): m_sContent(pszContent),
                                                                            m_sArguments(pszArguments)
  {
  }
  CContextMenuItem(const CContextMenuItem&) = delete;
  CContextMenuItem(CContextMenuItem&&) = delete;
  virtual ~CContextMenuItem() = default;

//Methods
  CContextMenuItem& operator=(const CContextMenuItem&) = delete;
  CContextMenuItem& operator=(CContextMenuItem&&) = delete;

  HRESULT GetContent(_In_ CComPtr<IXMLDOMDocument>& xml, _In_ CComPtr<IXMLDOMNode>& parentNode) override
  {
    //Create the "action" node
    CComPtr<IXMLDOMNode> actionNode;
    CComBSTR bstrAction(L"action");
    CComVariant varType(NODE_ELEMENT);
    CComBSTR bstrNS(L"");
    HRESULT hr = xml->createNode(varType, bstrAction, bstrNS, &actionNode);
    if (FAILED(hr))
      return hr;

    //Create the placement attribute
    hr = AddAttribute(actionNode, L"placement", L"contextMenu");
    if (FAILED(hr))
      return hr;

    //Create the content attribute
    hr = AddAttribute(actionNode, L"content", m_sContent.c_str());
    if (FAILED(hr))
      return hr;

    //Create the arguments attribute
    if (m_sArguments.length() != 0)
    {
      hr = AddAttribute(actionNode, L"arguments", m_sArguments.c_str());
      if (FAILED(hr))
        return hr;
    }

    //Finally update the DOM
    CComPtr<IXMLDOMNode> newChild;
    return parentNode->appendChild(actionNode, &newChild);
  }

//Member variables
  wstring m_sContent;
  wstring m_sArguments;
};


class IInput : public IGenericChild
{
};


class CTextBox : public IInput
{
public:
//Constructors / Destructors
  CTextBox() = default;
  CTextBox(const CTextBox&) = delete;
  CTextBox(CTextBox&&) = delete;
  virtual ~CTextBox() = default;

//Methods
  CTextBox& operator=(const CTextBox&) = delete;
  CTextBox& operator=(CTextBox&&) = delete;

  HRESULT GetContent(_In_ CComPtr<IXMLDOMDocument>& xml, _In_ CComPtr<IXMLDOMNode>& parentNode) override
  {
    //Create the "action" node
    CComPtr<IXMLDOMNode> inputNode;
    CComBSTR bstrAction(L"input");
    CComVariant varType(NODE_ELEMENT);
    CComBSTR bstrNS(L"");
    HRESULT hr = xml->createNode(varType, bstrAction, bstrNS, &inputNode);
    if (FAILED(hr))
      return hr;

    //Create the id attribute
    hr = AddAttribute(inputNode, L"id", m_sId.c_str());
    if (FAILED(hr))
      return hr;

    //Create the type attribute
    hr = AddAttribute(inputNode, L"type", L"text");
    if (FAILED(hr))
      return hr;

    //Create the title attribute
    if (m_sTitle.length() != 0)
    {
      hr = AddAttribute(inputNode, L"title", m_sTitle.c_str());
      if (FAILED(hr))
        return hr;
    }

    //Create the placeHolderContent attribute
    if (m_sPlaceholderContent.length() != 0)
    {
      hr = AddAttribute(inputNode, L"placeHolderContent", m_sPlaceholderContent.c_str());
      if (FAILED(hr))
        return hr;
    }

    //Create the defaultInput attribute
    if (m_sDefaultInput.length() != 0)
    {
      hr = AddAttribute(inputNode, L"defaultInput", m_sDefaultInput.c_str());
      if (FAILED(hr))
        return hr;
    }

    //Finally update the DOM
    CComPtr<IXMLDOMNode> newChild;
    return parentNode->appendChild(inputNode, &newChild);
  }

//Member variables
  wstring m_sId;
  wstring m_sTitle;
  wstring m_sPlaceholderContent;
  wstring m_sDefaultInput;
};


class CSelectionBoxItem : public IGenericChild
{
public:
//Constructors / Destructors
  CSelectionBoxItem() = default;
  CSelectionBoxItem(_In_z_ LPCWSTR pszId, _In_z_ LPCWSTR pszContent) : m_sId(pszId),
                                                                       m_sContent(pszContent)
  {
  }
  CSelectionBoxItem(const CSelectionBoxItem&) = delete;
  CSelectionBoxItem(CSelectionBoxItem&&) = delete;
  virtual ~CSelectionBoxItem() = default;

//Methods
  CSelectionBoxItem& operator=(const CSelectionBoxItem&) = delete;
  CSelectionBoxItem& operator=(CSelectionBoxItem&&) = delete;

  HRESULT GetContent(_In_ CComPtr<IXMLDOMDocument>& xml, _In_ CComPtr<IXMLDOMNode>& parentNode) override
  {
    //Create the "selection" node
    CComPtr<IXMLDOMNode> selectionNode;
    CComBSTR bstrAction(L"selection");
    CComVariant varType(NODE_ELEMENT);
    CComBSTR bstrNS(L"");
    HRESULT hr = xml->createNode(varType, bstrAction, bstrNS, &selectionNode);
    if (FAILED(hr))
      return hr;

    //Create the id attribute
    hr = AddAttribute(selectionNode, L"id", m_sId.c_str());
    if (FAILED(hr))
      return hr;

    //Create the content attribute
    hr = AddAttribute(selectionNode, L"content", m_sContent.c_str());
    if (FAILED(hr))
      return hr;

    //Finally update the DOM
    CComPtr<IXMLDOMNode> newChild;
    return parentNode->appendChild(selectionNode, &newChild);
  }

  //Member variables
  wstring m_sId;
  wstring m_sContent;
};


class CSelectionBox : public IInput
{
public:
//Constructors / Destructors
  CSelectionBox() = default;
  CSelectionBox(_In_z_ LPCWSTR pszId, _In_z_ LPCWSTR pszTitle, _In_z_ LPCWSTR pszDefaultSelectionBoxItemId) : m_sId(pszId),
                                                                                                              m_sTitle(pszTitle),
                                                                                                              m_sDefaultSelectionBoxItemId(pszDefaultSelectionBoxItemId)
  {
  }
  CSelectionBox(const CSelectionBox&) = delete;
  CSelectionBox(CSelectionBox&&) = delete;
  virtual ~CSelectionBox() = default;

//Methods
  CSelectionBox& operator=(const CSelectionBox&) = delete;
  CSelectionBox& operator=(CSelectionBox&&) = delete;

  HRESULT GetContent(_In_ CComPtr<IXMLDOMDocument>& xml, _In_ CComPtr<IXMLDOMNode>& parentNode) override
  {
    //Create the "action" node
    CComPtr<IXMLDOMNode> inputNode;
    CComBSTR bstrAction(L"input");
    CComVariant varType(NODE_ELEMENT);
    CComBSTR bstrNS(L"");
    HRESULT hr = xml->createNode(varType, bstrAction, bstrNS, &inputNode);
    if (FAILED(hr))
      return hr;

    //Create the id attribute
    hr = AddAttribute(inputNode, L"id", m_sId.c_str());
    if (FAILED(hr))
      return hr;

    //Create the type attribute
    hr = AddAttribute(inputNode, L"type", L"selection");
    if (FAILED(hr))
      return hr;

    //Create the title attribute
    if (m_sTitle.length() != 0)
    {
      hr = AddAttribute(inputNode, L"title", m_sTitle.c_str());
      if (FAILED(hr))
        return hr;
    }

    //Create the defaultInput attribute
    if (m_sDefaultSelectionBoxItemId.length() != 0)
    {
      hr = AddAttribute(inputNode, L"defaultInput", m_sDefaultSelectionBoxItemId.c_str());
      if (FAILED(hr))
        return hr;
    }

    //Handle all the items
    for (auto& c : m_Items)
    {
      hr = c->GetContent(xml, inputNode);
      if (FAILED(hr))
        return hr;
    }

    //Finally update the DOM
    CComPtr<IXMLDOMNode> newChild;
    return parentNode->appendChild(inputNode, &newChild);
  }

  //Member variables
  wstring                    m_sId;
  wstring                    m_sTitle;
  wstring                    m_sDefaultSelectionBoxItemId;
  vector<CSelectionBoxItem*> m_Items;
};


class IButton : public IGenericChild
{
};


class CButton : public IButton
{
public:
//Constructors / Destructors
  CButton() = default;
  CButton(const CButton&) = delete;
  CButton(CButton&&) = delete;
  virtual ~CButton() = default;

//Methods
  CButton& operator=(const CButton&) = delete;
  CButton& operator=(CButton&&) = delete;

  HRESULT GetContent(_In_ CComPtr<IXMLDOMDocument>& xml, _In_ CComPtr<IXMLDOMNode>& parentNode) override
  {
    //Create the "action" node
    CComPtr<IXMLDOMNode> inputNode;
    CComBSTR bstrAction(L"action");
    CComVariant varType(NODE_ELEMENT);
    CComBSTR bstrNS(L"");
    HRESULT hr = xml->createNode(varType, bstrAction, bstrNS, &inputNode);
    if (FAILED(hr))
      return hr;

    //Create the content attribute
    hr = AddAttribute(inputNode, L"content", m_sContent.c_str());
    if (FAILED(hr))
      return hr;

    //Create the arguments attribute
    hr = AddAttribute(inputNode, L"arguments", m_sArguments.c_str());
    if (FAILED(hr))
      return hr;

    //Create the imageUri attribute
    if (m_sImageUri.length() != 0)
    {
      hr = AddAttribute(inputNode, L"imageUri", m_sImageUri.c_str());
      if (FAILED(hr))
        return hr;
    }

    //Create the hint-inputId attribute
    hr = AddAttribute(inputNode, L"hint-inputId", m_sHintInputId.c_str());
    if (FAILED(hr))
      return hr;

    //Finally update the DOM
    CComPtr<IXMLDOMNode> newChild;
    return parentNode->appendChild(inputNode, &newChild);
  }

//Member variables
  wstring m_sContent;
  wstring m_sArguments;
  wstring m_sImageUri;
  wstring m_sHintInputId;
};


class CButtonDismiss : public IButton
{
public:
//Constructors / Destructors
  CButtonDismiss() = default;
  CButtonDismiss(const CButtonDismiss&) = delete;
  CButtonDismiss(CButtonDismiss&&) = delete;
  virtual ~CButtonDismiss() = default;

//Methods
  CButtonDismiss& operator=(const CButtonDismiss&) = delete;
  CButtonDismiss& operator=(CButtonDismiss&&) = delete;

  HRESULT GetContent(_In_ CComPtr<IXMLDOMDocument>& xml, _In_ CComPtr<IXMLDOMNode>& parentNode) override
  {
    //Create the "action" node
    CComPtr<IXMLDOMNode> actionNode;
    CComBSTR bstrAction(L"action");
    CComVariant varType(NODE_ELEMENT);
    CComBSTR bstrNS(L"");
    HRESULT hr = xml->createNode(varType, bstrAction, bstrNS, &actionNode);
    if (FAILED(hr))
      return hr;

    //Create the content attribute
    hr = AddAttribute(actionNode, L"content", m_sContent.c_str());
    if (FAILED(hr))
      return hr;

    //Create the arguments attribute
    hr = AddAttribute(actionNode, L"arguments", L"dismiss");
    if (FAILED(hr))
      return hr;

    //Create the activationType attribute
    hr = AddAttribute(actionNode, L"activationType", L"system");
    if (FAILED(hr))
      return hr;

    //Create the imageUri attribute
    if (m_sImageUri.length() != 0)
    {
      hr = AddAttribute(actionNode, L"imageUri", m_sImageUri.c_str());
      if (FAILED(hr))
        return hr;
    }

    //Finally update the DOM
    CComPtr<IXMLDOMNode> newChild;
    return parentNode->appendChild(actionNode, &newChild);
  }

  //Member variables
  wstring m_sContent;
  wstring m_sImageUri;
};


class CButtonSnooze : public IButton
{
public:
//Constructors / Destructors
  CButtonSnooze() = default;
  CButtonSnooze(const CButtonSnooze&) = delete;
  CButtonSnooze(CButtonSnooze&&) = delete;
  virtual ~CButtonSnooze() = default;

//Methods
  CButtonSnooze& operator=(const CButtonSnooze&) = delete;
  CButtonSnooze& operator=(CButtonSnooze&&) = delete;

  HRESULT GetContent(_In_ CComPtr<IXMLDOMDocument>& xml, _In_ CComPtr<IXMLDOMNode>& parentNode) override
  {
    //Create the "action" node
    CComPtr<IXMLDOMNode> actionNode;
    CComBSTR bstrAction(L"action");
    CComVariant varType(NODE_ELEMENT);
    CComBSTR bstrNS(L"");
    HRESULT hr = xml->createNode(varType, bstrAction, bstrNS, &actionNode);
    if (FAILED(hr))
      return hr;

    //Create the content attribute
    hr = AddAttribute(actionNode, L"content", m_sContent.c_str());
    if (FAILED(hr))
      return hr;

    //Create the arguments attribute
    hr = AddAttribute(actionNode, L"arguments", L"snooze");
    if (FAILED(hr))
      return hr;

    //Create the activationType attribute
    hr = AddAttribute(actionNode, L"activationType", L"system");
    if (FAILED(hr))
      return hr;

    //Create the imageUri attribute
    if (m_sImageUri.length() != 0)
    {
      hr = AddAttribute(actionNode, L"imageUri", m_sImageUri.c_str());
      if (FAILED(hr))
        return hr;
    }

    //Finally update the DOM
    CComPtr<IXMLDOMNode> newChild;
    return parentNode->appendChild(actionNode, &newChild);
  }

  //Member variables
  wstring m_sContent;
  wstring m_sImageUri;
};


class IAdaptiveSubgroup : public IGenericChild
{
};


class CAdaptiveSubgroup : public IAdaptiveSubgroup
{
public:
//Constructors / Destructors
  CAdaptiveSubgroup() noexcept : m_nHintWeight(-1),
                                 m_HintTextStacking(SubgroupTextStacking::Default)
  {
  }
  CAdaptiveSubgroup(const CAdaptiveSubgroup&) = delete;
  CAdaptiveSubgroup(CAdaptiveSubgroup&&) = delete;
  virtual ~CAdaptiveSubgroup() = default;

//Methods
  CAdaptiveSubgroup& operator=(const CAdaptiveSubgroup&) = delete;
  CAdaptiveSubgroup& operator=(CAdaptiveSubgroup&&) = delete;

  HRESULT GetContent(_In_ CComPtr<IXMLDOMDocument>& xml, _In_ CComPtr<IXMLDOMNode>& parentNode) override
  {
    //Create the "subgroup" node
    CComPtr<IXMLDOMNode> subgroupNode;
    CComBSTR bstrAction(L"subgroup");
    CComVariant varType(NODE_ELEMENT);
    CComBSTR bstrNS(L"");
    HRESULT hr = xml->createNode(varType, bstrAction, bstrNS, &subgroupNode);
    if (FAILED(hr))
      return hr;

    //Create the hint-weight attribute
    if (m_nHintWeight != -1)
    {
      CAtlStringW sHintWeight;
      sHintWeight.Format(L"%d", m_nHintWeight);
      hr = AddAttribute(subgroupNode, L"hint-weight", sHintWeight);
      if (FAILED(hr))
        return hr;
    }

    //Create the hint-textStacking attribute
    if (m_HintTextStacking != SubgroupTextStacking::Default)
    {
      switch (m_HintTextStacking)
      {
        case SubgroupTextStacking::Top:
        {
          hr = AddAttribute(subgroupNode, L"hint-textStacking", L"top");
          break;
        }
        case SubgroupTextStacking::Center:
        {
          hr = AddAttribute(subgroupNode, L"hint-textStacking", L"center");
          break;
        }
        case SubgroupTextStacking::Bottom:
        {
          hr = AddAttribute(subgroupNode, L"hint-textStacking", L"bottom");
          break;
        }
        default:
        {
#pragma warning(suppress: 26477)
          ATLASSERT(FALSE);
          break;
        }
      }
      if (FAILED(hr))
        return hr;
    }

    //Handle all the subgroups
    for (auto& c : m_Children)
    {
      hr = c->GetContent(xml, subgroupNode);
      if (FAILED(hr))
        return hr;
    }

    //Finally update the DOM
    CComPtr<IXMLDOMNode> newChild;
    return parentNode->appendChild(subgroupNode, &newChild);
  }

//Member variables
  int                             m_nHintWeight;
  SubgroupTextStacking            m_HintTextStacking;
  vector<IAdaptiveSubgroupChild*> m_Children;
};


class CAdaptiveGroup : public IGenericChild
{
public:
//Constructors / Destructors
  CAdaptiveGroup() = default;
  CAdaptiveGroup(const CAdaptiveGroup&) = delete;
  CAdaptiveGroup(CAdaptiveGroup&&) = delete;
  virtual ~CAdaptiveGroup() = default;

//Methods
  CAdaptiveGroup& operator=(const CAdaptiveGroup&) = delete;
  CAdaptiveGroup& operator=(CAdaptiveGroup&&) = delete;

  HRESULT GetContent(_In_ CComPtr<IXMLDOMDocument>& xml, _In_ CComPtr<IXMLDOMNode>& parentNode) override
  {
    //Create the "group" node
    CComPtr<IXMLDOMNode> groupNode;
    CComBSTR bstrGroup(L"group");
    CComVariant varType(NODE_ELEMENT);
    CComBSTR bstrNS(L"");
    HRESULT hr = xml->createNode(varType, bstrGroup, bstrNS, &groupNode);
    if (FAILED(hr))
      return hr;

    //Handle all the subgroups
    for (auto& c : m_Children)
    {
      hr = c->GetContent(xml, groupNode);
      if (FAILED(hr))
        return hr;
    }

    //Finally update the DOM
    CComPtr<IXMLDOMNode> newChild;
    return parentNode->appendChild(groupNode, &newChild);
  }

//Member variables
  vector<IAdaptiveSubgroup*> m_Children;
};


class CActions : public IGenericChild
{
public:
//Constructors / Destructors
  CActions() = default;
  CActions(const CActions&) = delete;
  CActions(CActions&&) = delete;
  virtual ~CActions() = default;

//Methods
  CActions& operator=(const CActions&) = delete;
  CActions& operator=(CActions&&) = delete;

  HRESULT GetContent(_In_ CComPtr<IXMLDOMDocument>& xml, _In_ CComPtr<IXMLDOMNode>& parentNode) override
  {
    //Create the "actions" node
    CComPtr<IXMLDOMNode> actionsNode;
    CComBSTR bstrActions(L"actions");
    CComVariant varType(NODE_ELEMENT);
    CComBSTR bstrNS(L"");
    HRESULT hr = xml->createNode(varType, bstrActions, bstrNS, &actionsNode);
    if (FAILED(hr))
      return hr;

    //Handle all the children
    bool bSomeChildren = false;
    for (auto& c : m_Inputs)
    {
      hr = c->GetContent(xml, actionsNode);
      if (FAILED(hr))
        return hr;
      bSomeChildren = true;
    }
    for (auto& c : m_Buttons)
    {
      hr = c->GetContent(xml, actionsNode);
      if (FAILED(hr))
        return hr;
      bSomeChildren = true;
    }
    for (auto& c : m_ContextMenuItems)
    {
      hr = c->GetContent(xml, actionsNode);
      if (FAILED(hr))
        return hr;
      bSomeChildren = true;
    }

    //Finally update the DOM
    if (bSomeChildren)
    {
      CComPtr<IXMLDOMNode> newRootNode;
      return parentNode->appendChild(actionsNode, &newRootNode);
    }

    return S_OK;
  }

//Member variables
  vector<IContextMenuItem*> m_ContextMenuItems;
  vector<IInput*>           m_Inputs;
  vector<IButton*>          m_Buttons;
};


class CActionsSnoozeAndDismiss : public IGenericChild
{
public:
//Constructors / Destructors
  CActionsSnoozeAndDismiss() = default;
  CActionsSnoozeAndDismiss(const CActionsSnoozeAndDismiss&) = delete;
  CActionsSnoozeAndDismiss(CActionsSnoozeAndDismiss&&) = delete;
  virtual ~CActionsSnoozeAndDismiss() = default;

//Methods
  CActionsSnoozeAndDismiss& operator=(const CActionsSnoozeAndDismiss&) = delete;
  CActionsSnoozeAndDismiss& operator=(CActionsSnoozeAndDismiss&&) = delete;

  HRESULT GetContent(_In_ CComPtr<IXMLDOMDocument>& xml, _In_ CComPtr<IXMLDOMNode>& parentNode) override
  {
    //Create the "actions" node
    CComPtr<IXMLDOMNode> actionsNode;
    CComBSTR bstrActions(L"actions");
    CComVariant varType(NODE_ELEMENT);
    CComBSTR bstrNS(L"");
    HRESULT hr = xml->createNode(varType, bstrActions, bstrNS, &actionsNode);
    if (FAILED(hr))
      return hr;

    //Create the hint-systemCommands attribute
    hr = AddAttribute(actionsNode, L"hint-systemCommands", L"SnoozeAndDismiss");
    if (FAILED(hr))
      return hr;

    //Handle all the children
    for (auto& c : m_ContextMenuItems)
    {
      hr = c->GetContent(xml, actionsNode);
      if (FAILED(hr))
        return hr;
    }

    //Finally update the DOM
    CComPtr<IXMLDOMNode> newRootNode;
    return parentNode->appendChild(actionsNode, &newRootNode);
  }

//Member variables
  vector<CContextMenuItem*> m_ContextMenuItems;
};


class CContent
{
public:
//Constructors / Destructors
  CContent() noexcept : m_Scenario(Scenario::Default),
                        m_Duration(Duration::Default),
                        m_Type(TemplateType::Generic)
  {
    memset(&m_DisplayTimestamp, 0, sizeof(m_DisplayTimestamp));
  }

//Methods
  HRESULT GetContent(_Inout_ wstring& sXML)
  {
    ATL::CComPtr<IXMLDOMDocument> xml2;
    HRESULT hr = xml2.CoCreateInstance(__uuidof(DOMDocument60));
    if (FAILED(hr))
      return hr;
    hr = GetContent(xml2);
    if (FAILED(hr))
      return hr;
    CComBSTR bstrXML;
    hr = xml2->get_xml(&bstrXML);
    if (FAILED(hr))
      return hr;
    sXML = bstrXML;
    return S_OK;
  }

  HRESULT GetContent(_Inout_ CComPtr<IXMLDOMDocument>& xml)
  {
    //Create the "toast" root node
    CComPtr<IXMLDOMNode> toastNode;
    CComBSTR bstrToast(L"toast");
    CComVariant varType(NODE_ELEMENT);
    CComBSTR bstrNS(L"");
    HRESULT hr = xml->createNode(varType, bstrToast, bstrNS, &toastNode);
    if (FAILED(hr))
      return hr;

    //Create the visual node
    hr = m_Visual.GetContent(xml, toastNode, m_Type);
    if (FAILED(hr))
      return hr;
    if (m_Type == TemplateType::Generic)
    {
      //Create the scenario attribute
      if (m_Scenario != Scenario::Default)
      {
        switch (m_Scenario)
        {
          case Scenario::Alarm:
          {
            hr = AddAttribute(toastNode, L"scenario", L"alarm");
            break;
          }
          case Scenario::Reminder:
          {
            hr = AddAttribute(toastNode, L"scenario", L"reminder");
            break;
          }
          case Scenario::IncomingCall:
          {
            hr = AddAttribute(toastNode, L"scenario", L"incomingCall");
            break;
          }
          default:
          {
#pragma warning(suppress: 26477)
            ATLASSERT(FALSE);
            break;
          }
        }
        if (FAILED(hr))
          return hr;
      }

      //Create the duration attribute
      if (m_Duration != Duration::Default)
      {
        switch (m_Duration)
        {
          case Duration::Short:
          {
            hr = AddAttribute(toastNode, L"duration", L"short");
            break;
          }
          case Duration::Long:
          {
            hr = AddAttribute(toastNode, L"duration", L"long");
            break;
          }
          default:
          {
#pragma warning(suppress: 26477)
            ATLASSERT(FALSE);
            break;
          }
        }
        if (FAILED(hr))
          return hr;
      }

      //Create the launch attribute
      if (m_sLaunch.length() != 0)
      {
        hr = AddAttribute(toastNode, L"launch", m_sLaunch.c_str());
        if (FAILED(hr))
          return hr;
      }

      //Create the displayTimestamp attribute
      if (m_DisplayTimestamp.wYear)
      {
        CAtlStringW sDisplayTimestamp;
        sDisplayTimestamp.Format(L"%04d-%02d-%02dT%02d:%02d:%02dZ", static_cast<int>(m_DisplayTimestamp.wYear), static_cast<int>(m_DisplayTimestamp.wMonth), static_cast<int>(m_DisplayTimestamp.wDay),
                                 static_cast<int>(m_DisplayTimestamp.wHour), static_cast<int>(m_DisplayTimestamp.wMinute), static_cast<int>(m_DisplayTimestamp.wSecond));
        hr = AddAttribute(toastNode, L"displayTimestamp", sDisplayTimestamp);
        if (FAILED(hr))
          return hr;
      }

      //Create the audio node
      hr = m_Audio.GetContent(xml, toastNode);
      if (FAILED(hr))
        return hr;

      //Create the actions node
      hr = m_Actions.GetContent(xml, toastNode);
      if (FAILED(hr))
        return hr;
    }

    //Finally update the DOM
    CComPtr<IXMLDOMNode> newRootNode;
    return xml->appendChild(toastNode, &newRootNode);
  }

//Member variables
  CVisual      m_Visual;
  CAudio       m_Audio;
  CActions     m_Actions;
  Scenario     m_Scenario;
  Duration     m_Duration;
  wstring      m_sLaunch;
  SYSTEMTIME   m_DisplayTimestamp;
  TemplateType m_Type;
};


//The notification interface used by CManager::Show
class INotifier
{
public:
//Methods
  virtual void OnToastActivated(_In_opt_ IToastNotification* pSender, _In_opt_ IInspectable* pArgs) = 0;
  virtual void OnToastDismissed(_In_opt_ IToastNotification* pSender, _In_ ToastDismissalReason reason) = 0;
  virtual void OnToastFailed(_In_opt_ IToastNotification* pSender, _In_ HRESULT errorCode) = 0;
};


//Class which represents a single popped toast
class CToast : public ComPtr<IToastNotification>
{
public:
//Constructors / Destructors
  CToast() noexcept
  {
    m_activatedToken.value = 0;
    m_dismissedToken.value = 0;
    m_failedToken.value = 0;
  }

  CToast(const CToast&) = delete;
  CToast(CToast&&) = delete;

  virtual ~CToast()
  {
#pragma warning(suppress: 26447)
    Reset();
  }

//Methods
  CToast& operator=(const CToast&) = delete;
  CToast& operator=(CToast&&) = delete;

#pragma warning(suppress: 26434)
  void Reset()
  {
    RemoveEventHandlers();
    __super::Reset();
  }

  HRESULT Create(_In_z_ LPCWSTR pszContent)
  {
    //Create the XML document for the toast
    ComPtr<IXmlDocument> xml;
    HRESULT hr = RoActivateInstance(HStringReference(RuntimeClass_Windows_Data_Xml_Dom_XmlDocument).Get(), &xml);
    if (FAILED(hr))
      return hr;
    ComPtr<IXmlDocumentIO> xmlIO;
    hr = xml.As(&xmlIO);
    if (FAILED(hr))
      return hr;
    hr = xmlIO->LoadXml(HStringReference(pszContent).Get());
    if (FAILED(hr))
      return hr;

    //Create the toast notification
    ComPtr<IToastNotificationFactory> toastNotificationFactory;
    hr = GetActivationFactory(HStringReference(RuntimeClass_Windows_UI_Notifications_ToastNotification).Get(), &toastNotificationFactory);
    if (FAILED(hr))
      return hr;
    hr = RemoveEventHandlers();
    if (FAILED(hr))
      return hr;
    return toastNotificationFactory->CreateToastNotification(xml.Get(), ReleaseAndGetAddressOf());
  }

protected:
//Methods
  HRESULT RemoveEventHandlers()
  {
    HRESULT hr = S_FALSE;
    if (m_activatedToken.value != 0)
    {
#pragma warning(suppress: 26477)
      ATLASSERT(operator->() != nullptr);
      hr = operator->()->remove_Activated(m_activatedToken);
      if (FAILED(hr))
        return hr;
      m_activatedToken.value = 0;
    }

    if (m_dismissedToken.value != 0)
    {
#pragma warning(suppress: 26477)
      ATLASSERT(operator->() != nullptr);
      hr = operator->()->remove_Dismissed(m_dismissedToken);
      if (FAILED(hr))
        return hr;
      m_dismissedToken.value = 0;
    }

    if (m_failedToken.value != 0)
    {
#pragma warning(suppress: 26477)
      ATLASSERT(operator->() != nullptr);
      hr = operator->()->remove_Failed(m_failedToken);
      if (FAILED(hr))
        return hr;
      m_failedToken.value = 0;
    }

    return hr;
  }

  HRESULT SetupEventHandlers(_In_ INotifier* eventHandler)
  {
    //Remove any currently setup event handlers
    HRESULT hr = RemoveEventHandlers();
    if (FAILED(hr))
      return hr;

    //Hook up the Activated event handler
#pragma warning(suppress: 26477)
    ATLASSERT(m_activatedToken.value == 0);
#pragma warning(suppress: 26477)
    ATLASSERT(operator->() != nullptr);
    auto activatedEventHandler = Callback < Implements < RuntimeClassFlags<ClassicCom>, ITypedEventHandler<ToastNotification*, IInspectable* >> >(
        [eventHandler](IToastNotification* pSender, IInspectable* args)
      {
        eventHandler->OnToastActivated(pSender, args);
        return S_OK;
      });
    if (activatedEventHandler == nullptr)
      return E_OUTOFMEMORY;
    hr = operator->()->add_Activated(activatedEventHandler.Get(), &m_activatedToken);
    if (FAILED(hr))
      return hr;

    //Hook up the Dismissed event handler
#pragma warning(suppress: 26477)
    ATLASSERT(m_dismissedToken.value == 0);
#pragma warning(suppress: 26477)
    ATLASSERT(operator->() != nullptr);
    auto dismissedEventHandler = Callback < Implements < RuntimeClassFlags<ClassicCom>, ITypedEventHandler<ToastNotification*, ToastDismissedEventArgs* >> >(
        [eventHandler](IToastNotification* pSender, IToastDismissedEventArgs* pEventArgs)
      {
        ToastDismissalReason reason;
        if (SUCCEEDED(pEventArgs->get_Reason(&reason)))
          eventHandler->OnToastDismissed(pSender, reason);
#pragma warning(suppress: 26429)
        return S_OK;
#pragma warning(suppress: 26429)
      });
    if (dismissedEventHandler == nullptr)
      return E_OUTOFMEMORY;
    hr = operator->()->add_Dismissed(dismissedEventHandler.Get(), &m_dismissedToken);
    if (FAILED(hr))
      return hr;

    //Hook up the Failed event handler
#pragma warning(suppress: 26477)
    ATLASSERT(m_failedToken.value == 0);
#pragma warning(suppress: 26477)
    ATLASSERT(operator->() != nullptr);
    auto failedEventHandler = Callback < Implements < RuntimeClassFlags<ClassicCom>, ITypedEventHandler<ToastNotification*, ToastFailedEventArgs* >> >(
        [eventHandler](IToastNotification* pSender, IToastFailedEventArgs* pEventArgs)
      {
        HRESULT errorCode;
        if (SUCCEEDED(pEventArgs->get_ErrorCode(&errorCode)))
          eventHandler->OnToastFailed(pSender, errorCode);
#pragma warning(suppress: 26429)
        return S_OK;
#pragma warning(suppress: 26429)
      });
    if (failedEventHandler == nullptr)
      return E_OUTOFMEMORY;
    hr = operator->()->add_Failed(failedEventHandler.Get(), &m_failedToken);
    return hr;
  }

//Member variables
  EventRegistrationToken m_activatedToken;
  EventRegistrationToken m_dismissedToken;
  EventRegistrationToken m_failedToken;

  friend class CManager;
};


//The main class
class CManager : public ComPtr<IToastNotifier>
{
public:
//Methods
  static HRESULT GetExecutablePath(_Inout_ wstring& sModuleName)
  {
    sModuleName.resize(_MAX_PATH);
#pragma warning(suppress: 26446)
    const DWORD dwGMFN = GetModuleFileNameW(nullptr, &(sModuleName[0]), _MAX_PATH);
#pragma warning(suppress: 26489)
    sModuleName.resize(dwGMFN);
    if (dwGMFN == 0)
      return AtlHresultFromLastError();
    return S_OK;
  }

  static HRESULT RegisterForNotificationSupport(_In_z_ LPCWSTR pszAppName, _In_z_ LPCWSTR pszApplicationPath, _In_z_ LPCWSTR pszAppUserModelID, _In_ GUID ClsidToastActivator = GUID_NULL,
                                                _In_opt_z_ LPCWSTR pszArguments = nullptr, _In_opt_z_ LPCWSTR pszWorkingDirectory = nullptr, _In_opt_z_ LPCWSTR pszDescription = nullptr, _In_opt_z_ LPCWSTR pszIconPath = nullptr, _In_ int nIcon = 0)
  {
    //Find the location of the start menu programs folder
    PWSTR pszPath = nullptr;
    const HRESULT hr = SHGetKnownFolderPath(FOLDERID_Programs, 0, nullptr, &pszPath);
    if (FAILED(hr))
      return hr;

    //Form the path to the shortcut file
    CPathW shortcutPath(pszPath);
    CoTaskMemFree(pszPath);
    shortcutPath.AddBackslash();
    shortcutPath.Append(pszAppName);
    shortcutPath.AddExtension(L".lnk");

    //Nothing to do if the shortcut file already exists
    if (shortcutPath.FileExists())
      return S_FALSE;

    //Delegate the work to the method which creates the shortcut
    return CreateStartMenuShortcut(shortcutPath, pszApplicationPath, pszAppUserModelID, ClsidToastActivator, pszArguments, pszWorkingDirectory, pszDescription, pszIconPath, nIcon);
  }

  static HRESULT CreateStartMenuShortcut(_In_z_ LPCWSTR pszShortcutPath, _In_z_ LPCWSTR pszApplicationPath, _In_z_ LPCWSTR pszAppUserModelID, _In_ GUID ClsidToastActivator = GUID_NULL, 
                                         _In_opt_z_ LPCWSTR pszArguments = nullptr, _In_opt_z_ LPCWSTR pszWorkingDirectory = nullptr, _In_opt_z_ LPCWSTR pszDescription = nullptr, _In_opt_z_ LPCWSTR pszIconPath = nullptr, _In_ int nIcon = 0)
  {
    //Create the Shell link COM object
    ComPtr<IShellLinkW> shellLink;
    HRESULT hr = CoCreateInstance(CLSID_ShellLink, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&shellLink));
    if (FAILED(hr))
      return hr;

    //Set the path
#pragma warning(suppress: 26486)
    hr = shellLink->SetPath(pszApplicationPath);
    if (FAILED(hr))
      return hr;

    //Set the arguments if required
    if (pszArguments != nullptr)
    {
#pragma warning(suppress: 26486)
      hr = shellLink->SetArguments(pszArguments);
      if (FAILED(hr))
        return hr;
    }

    //Set the working directory if required
    if (pszWorkingDirectory != nullptr)
    {
#pragma warning(suppress: 26486)
      hr = shellLink->SetWorkingDirectory(pszWorkingDirectory);
      if (FAILED(hr))
        return hr;
    }

    //Set the description if required
    if (pszDescription != nullptr)
    {
#pragma warning(suppress: 26486)
      hr = shellLink->SetDescription(pszDescription);
      if (FAILED(hr))
        return hr;
    }

    //Set the icon location if required
    if (pszIconPath != nullptr)
    {
#pragma warning(suppress: 26486)
      hr = shellLink->SetIconLocation(pszIconPath, nIcon);
      if (FAILED(hr))
        return hr;
    }

    //Get the IPropertyStore interface from the shell link object
    ComPtr<IPropertyStore> propertyStore;
    hr = shellLink.As(&propertyStore);
    if (FAILED(hr))
      return hr;
    
    //Set the AppUserModelID
    PROPVARIANT AppIdPropVar;
#pragma warning(suppress: 26486)
    hr = InitPropVariantFromString(pszAppUserModelID, &AppIdPropVar);
    if (FAILED(hr))
      return hr;
#pragma warning(suppress: 26486)
    hr = propertyStore->SetValue(PKEY_AppUserModel_ID, AppIdPropVar);
    PropVariantClear(&AppIdPropVar);
    if (FAILED(hr))
      return hr;

    //Set the Toast Activator CLSID if required
    if (ClsidToastActivator != GUID_NULL)
    {
      PROPVARIANT toastActivatorPropVar;
      toastActivatorPropVar.vt = VT_CLSID;
      toastActivatorPropVar.puuid = &ClsidToastActivator;
#pragma warning(suppress: 26486)
      hr = propertyStore->SetValue(PKEY_AppUserModel_ToastActivatorCLSID, toastActivatorPropVar);
      if (FAILED(hr))
        return hr;
    }

    //Commit the property store changes
#pragma warning(suppress: 26486)
    hr = propertyStore->Commit();
    if (FAILED(hr))
      return hr;

    //Get the IPersistFile interface from the shell link object
    ComPtr<IPersistFile> persistFile;
    hr = shellLink.As(&persistFile);
    if (FAILED(hr))
      return hr;

    //Save the shortcut
#pragma warning(suppress: 26486)
    return persistFile->Save(pszShortcutPath, TRUE);
  }

  HRESULT Create(_In_z_ LPCWSTR pszAppUserModelID)
  {
    //Create the toast notifier
    ComPtr<IToastNotificationManagerStatics> toastStatics;
    HRESULT hr = Windows::Foundation::GetActivationFactory(HStringReference(RuntimeClass_Windows_UI_Notifications_ToastNotificationManager).Get(), &toastStatics);
    if (FAILED(hr))
      return hr;
    return toastStatics->CreateToastNotifierWithId(HStringReference(pszAppUserModelID).Get(), ReleaseAndGetAddressOf());
  }

  HRESULT Show(_Inout_ CToast& toast, _In_opt_ INotifier* eventHandler = nullptr)
  {
    //Hook up the event handlers
    if (eventHandler != nullptr)
    {
      const HRESULT hr = toast.SetupEventHandlers(eventHandler);
      if (FAILED(hr))
        return hr;
    }

    //Finally show the toast notification
    return operator->()->Show(toast.Get());
  }
};


}; //namespace Toast++

#endif //#ifndef __TOASTPP_H__
