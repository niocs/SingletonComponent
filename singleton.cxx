
#include <singleton.hxx>
#include <cstdint>
#include <com/sun/star/uno/XComponentContext.hpp>
#include <cppuhelper/supportsservice.hxx>
#include <uno/lbnames.h>
#include <cppuhelper/factory.hxx>
#include <com/sun/star/lang/XSingleComponentFactory.hpp>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/registry/XRegistryKey.hpp>

using namespace ::rtl; // for OUString
using namespace ::com::sun::star; // for sdk interfaces
using namespace ::com::sun::star::uno; // for basic types
using namespace ::osl;
using namespace ::cppu;
using namespace ::com::sun::star::lang;
using namespace ::com::sun::star::registry;



#define SERVICE_NAME "inco.niocs.test.BoolDataStore"

OUString SAL_CALL BoolDataStoreImpl::getAddress()
{
    return OUString::number(reinterpret_cast<std::uintptr_t>(this));
}

// DataStoreImpl : XServiceInfo
OUString SAL_CALL BoolDataStoreImpl::getImplementationName()
    throw (RuntimeException)
{
    return IMPLEMENTATION_NAME;
}

sal_Bool SAL_CALL BoolDataStoreImpl::supportsService( const OUString& rServiceName )
    throw (RuntimeException)
{
    return cppu::supportsService(this, rServiceName);
}

Sequence< OUString > SAL_CALL BoolDataStoreImpl::getSupportedServiceNames(  )
    throw (RuntimeException)
{
    return BoolDataStoreImpl_getSupportedServiceNames();
}


struct Instance {
    explicit Instance(
	Reference<XComponentContext> const & /*rxContext*/):
	instance(
	    static_cast<cppu::OWeakObject *>(new BoolDataStoreImpl()))
    {}
    Reference<XInterface> instance;
};


struct Singleton:
    public rtl::StaticWithArg<
    Instance, Reference<XComponentContext>, Singleton>
{};


Sequence< OUString > SAL_CALL BoolDataStoreImpl_getSupportedServiceNames()
    throw (RuntimeException)
{
    Sequence < OUString > aRet(1);
    OUString* pArray = aRet.getArray();
    pArray[0] =  OUString ( SERVICE_NAME );
    return aRet;    
}

Reference< XInterface > SAL_CALL BoolDataStoreImpl_createInstance( const Reference< XComponentContext > & rxContext )
    throw( Exception )
{
    return cppu::acquire(static_cast<cppu::OWeakObject *>(
			     Singleton::get(rxContext).instance.get()));
}

extern "C" SAL_DLLPUBLIC_EXPORT void * SAL_CALL component_getFactory(const sal_Char * pImplName, void * /*pServiceManager*/, void * pRegistryKey)
{
    void * pRet = 0;

    if (rtl_str_compare( pImplName, IMPLEMENTATION_NAME ) == 0)
    {
        Reference< XSingleComponentFactory > xFactory( createSingleComponentFactory(
            BoolDataStoreImpl_createInstance,
            OUString( IMPLEMENTATION_NAME ),
            BoolDataStoreImpl_getSupportedServiceNames() ) );

        if (xFactory.is())
        {
            xFactory->acquire();
            pRet = xFactory.get();
        }
    }

    return pRet;
}

extern "C" SAL_DLLPUBLIC_EXPORT void SAL_CALL
component_getImplementationEnvironment(
    char const ** ppEnvTypeName, uno_Environment **)
{
    *ppEnvTypeName = CPPU_CURRENT_LANGUAGE_BINDING_NAME;
}
