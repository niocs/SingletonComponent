#ifndef INCO_NIOCS_TEST_SINGLETONCOMPONENT_HXX
#define INCO_NIOCS_TEST_SINGLETONCOMPONENT_HXX

#include <cppuhelper/implbase2.hxx>
#include <inco/niocs/test/XBoolDataStore.hpp>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/uno/XInterface.hpp>

#define IMPLEMENTATION_NAME "inco.niocs.test.BoolDataStoreImpl"

namespace com
{
    namespace sun
    {
	namespace star
	{
	    namespace uno
	    {
		class XComponentContext;
	    }
	}
    }
}


class BoolDataStoreImpl : public cppu::WeakImplHelper2
<
    css::lang::XServiceInfo,
    inco::niocs::test::XBoolDataStore
>
{
    sal_Bool bData;
public:
    BoolDataStoreImpl() throw ()
            : bData(false)
    {}
    virtual ~BoolDataStoreImpl() {}

    // XBoolDataStore methods
    virtual sal_Bool SAL_CALL getBool() { return bData; }
    virtual void     SAL_CALL setBool( const sal_Bool bSet ) { bData = bSet; }
    virtual ::rtl::OUString SAL_CALL getAddress();
    
    // XServiceInfo methods
    virtual ::rtl::OUString SAL_CALL getImplementationName()
        throw (css::uno::RuntimeException);
    virtual sal_Bool SAL_CALL supportsService( const ::rtl::OUString& aServiceName )
        throw (css::uno::RuntimeException);
    virtual css::uno::Sequence< ::rtl::OUString > SAL_CALL getSupportedServiceNames()
        throw (css::uno::RuntimeException);
};


css::uno::Sequence< ::rtl::OUString > SAL_CALL BoolDataStoreImpl_getSupportedServiceNames()
    throw (css::uno::RuntimeException);

::com::sun::star::uno::Reference< ::com::sun::star::uno::XInterface > SAL_CALL BoolDataStoreImpl_createInstance(
    const css::uno::Reference< css::uno::XComponentContext > & rContext )
    throw( css::uno::Exception );

#endif
