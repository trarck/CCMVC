﻿#include "LayerController.h"
#include "Layer.h"

NS_CC_YHMVC_BEGIN

LayerController::LayerController()
:m_sDefineDataName("")
,m_pLayer(NULL)
,m_childLayerControllers(NULL)
,m_parent(NULL)
{
    
}

LayerController::~LayerController()
{
    CC_SAFE_RELEASE_NULL(m_pLayer);
    CC_SAFE_RELEASE_NULL(m_childLayerControllers);
    m_parent=NULL;
}

// on "init" you need to initialize your instance
bool LayerController::init()
{
    m_childLayerControllers=new CCArray();
    m_childLayerControllers->init();
    return true;
}

//默认从描述文件中加载
void LayerController::loadLayer()
{
    if(m_sDefineDataName==""){
        //create a empty layer
        Layer* layer=new Layer();
        layer->init();
        setLayer(layer);
		layer->release();
    }else{
        //TODO load from define file

    }
}

bool LayerController::isLayerLoaded()
{
    return m_tState.isLoaded;
}

void LayerController::setLayer(Layer* layer)
{
    CC_SAFE_RETAIN(layer);
	if(m_pLayer) m_pLayer->setLayerController(NULL);
    CC_SAFE_RELEASE(m_pLayer);
    m_pLayer = layer;
	if(m_pLayer) m_pLayer->setLayerController(this);
}

Layer* LayerController::getLayer()
{
    if (!m_pLayer) {
        this->loadLayer();
        m_tState.isLoaded=true;
        this->layerDidLoad();
    }
    return m_pLayer;
}

//layer.已经加载。如果是从配置文件中加载。此处提供而外操作
//比如绑定事件，修改文体内容
void LayerController::layerDidLoad()
{
    
}

/**
 * 当layer的onEnter事件执行时调用
 */
void LayerController::onLayerEnter()
{

}

/**
 * 当layer的onExit事件执行时调用
 */
void LayerController::onLayerExit()
{

}

void LayerController::layerWillAppear()
{
    
}

void LayerController::layerDidAppear()
{
    
}

void LayerController::layerWillDisappear()
{
    
}

void LayerController::layerDidDisappear()
{
    
}

//==================child layer controller=================//

void LayerController::addChildLayerController(LayerController* layerController)
{
    layerController->willAddToParentLayerController(this);
    m_childLayerControllers->addObject(layerController);
    layerController->setParent(this);
    layerController->didAddToParentLayerController(this);
}

void LayerController::removeChildLayerController(LayerController* layerController)
{
    layerController->willRemoveFromParentLayerController();
    m_childLayerControllers->removeObject(layerController);
    layerController->setParent(NULL);
    layerController->didRemoveFromParentLayerController();
}

void LayerController::removeFromParentLayerController()
{
    if (m_parent!=NULL){
        m_parent->removeChildLayerController(this);
    }
}

LayerController* LayerController::getLayerControllerByName(const std::string& name)
{
    CCObject* pObj=NULL;
    LayerController* layerController=NULL;
    CCARRAY_FOREACH(m_childLayerControllers, pObj){
        layerController=static_cast<LayerController*>(pObj);
        if (name.compare(layerController->getName())==0) {
            return layerController;
        }
    }
    return NULL;
}

void LayerController::willAddToParentLayerController(LayerController* parent)
{
    
}

void LayerController::didAddToParentLayerController(LayerController* parent)
{
    
}

void LayerController::willRemoveFromParentLayerController()
{
    
}

void LayerController::didRemoveFromParentLayerController()
{
    
}

NS_CC_YHMVC_END