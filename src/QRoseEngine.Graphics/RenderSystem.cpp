#include <QRoseEngine.Graphics/RenderSystem.hpp>

#include <QRoseEngine.Core/Components/TransformationComponent.hpp>
#include <QRoseEngine.Graphics/Components/MeshComponent.hpp>

using namespace QRose;

RenderSystem::RenderSystem(Ptr<Render> pRender, Ptr<Manager<TransformationComponent>> pTransformationComponentManager,
	Ptr<Manager<MeshComponent>> pMeshComponentManager, Ptr<Manager<CameraComponent>> pCameraComponentManager)
	: pRender(pRender), pTransformationComponentManager(pTransformationComponentManager),
	pMeshComponentManager(pMeshComponentManager), pCameraComponentManager(pCameraComponentManager)
{
	if(pRender == nullptr) throw std::invalid_argument("pRender == nullptr");
	if(pTransformationComponentManager == nullptr) 
		throw std::invalid_argument("pTransformationComponentManager == nullptr");
	if (pMeshComponentManager == nullptr) throw std::invalid_argument("pMeshComponentManager == nullptr");
	if (pCameraComponentManager == nullptr) throw std::invalid_argument("pCameraComponentManager == nullptr");
}

RenderSystem::~RenderSystem()
{
}

void RenderSystem::Update(double dt)
{
	pRender->ClearView();
	pRender->BeginDrawing();

	//Matrix4x4 viewMatrix;
	//viewMatrix = viewMatrix.Translate(Vector3(0.5f, 0.0f, -3.0f));
	//pRender->SetViewMatrix(viewMatrix);
	if (pCameraComponentManager->ComponentsTotal() > 0)
	{
		// TODO: handle multiple cameras
		std::pair<Handle, CameraComponent> camera = pCameraComponentManager->GetAllComponents()[0];
		if (pTransformationComponentManager->Contains(camera.first))
		{
			TransformationComponent& cameraTransformationComponent = pTransformationComponentManager->GetComponent(camera.first);
			Matrix4x4 viewMatrix;
			viewMatrix = viewMatrix.Translate(cameraTransformationComponent.position);
			pRender->SetViewMatrix(viewMatrix);
		}
	}

	const std::vector<std::pair<Handle, MeshComponent>>& entitiesWithMeshes = pMeshComponentManager->GetAllComponents();
	std::vector<std::tuple<MeshComponent, TransformationComponent>> toDraw;
	toDraw.reserve(entitiesWithMeshes.size());
	for (auto& entityWithMesh : entitiesWithMeshes)
	{
		if (pTransformationComponentManager->Contains(entityWithMesh.first))
		{
			toDraw.push_back(std::make_tuple(entityWithMesh.second,
				pTransformationComponentManager->GetComponent(entityWithMesh.first)));
		}
	}
	for (const auto& toDrawTuple : toDraw)
	{
		const MeshComponent& meshComponent = std::get<0>(toDrawTuple);
		const TransformationComponent& transform = std::get<1>(toDrawTuple);
		Matrix4x4 modelMatrix;
		modelMatrix = modelMatrix.Translate(transform.position);
		modelMatrix = modelMatrix.Rotate(transform.rotation);
		modelMatrix = modelMatrix.Scale(transform.scale);
		pRender->DrawMesh(meshComponent.meshId, modelMatrix);
	}

	pRender->Present();
}