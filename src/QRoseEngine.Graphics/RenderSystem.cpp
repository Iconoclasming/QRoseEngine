#include <QRoseEngine.Graphics/RenderSystem.hpp>

using namespace QRose;

RenderSystem::RenderSystem(Ptr<Render> pRender, Ptr<World> pWorld)
	: pRender(pRender), pWorld(pWorld), pCameraComponentStorage(nullptr),
	  pTransformComponentStorage(nullptr), pMeshComponentStorage(nullptr)
{
	if (pRender == nullptr) throw std::invalid_argument("pRender == nullptr");
	if (pWorld == nullptr) throw std::invalid_argument("pWorld == nullptr");
}

RenderSystem::~RenderSystem()
{
}

void RenderSystem::Update(double dt)
{
	if(pCameraComponentStorage == nullptr)
	{
		pCameraComponentStorage = pWorld->Get<Storage<CameraComponent>>();
	}
	if(pTransformComponentStorage == nullptr)
	{
		pTransformComponentStorage = pWorld->Get<Storage<TransformComponent>>();
	}
	if(pMeshComponentStorage == nullptr)
	{
		pMeshComponentStorage = pWorld->Get<Storage<MeshComponent>>();
	}

	if (pCameraComponentStorage->Size() > 0)
	{
		CameraComponent cameraComponent = pCameraComponentStorage->At(0);
		// TODO: handle multiple cameras
		if(pTransformComponentStorage->Has(cameraComponent.id))
		{
			TransformComponent& cameraTransform = pTransformComponentStorage->Get(cameraComponent.id);
			Matrix4x4 viewMatrix;
			viewMatrix = viewMatrix.Translate(cameraTransform.position);
			pRender->SetViewMatrix(viewMatrix);
		}
	}

	std::vector<std::tuple<MeshComponent*, TransformComponent*>> toDraw;
	MeshComponent* meshComponents = pMeshComponentStorage->GetAll();
	for(int i = 0; i < pMeshComponentStorage->Size(); i++)
	{
		if(pTransformComponentStorage->Has(meshComponents[i].id))
		{
			TransformComponent* pTransformComponent = &pTransformComponentStorage->Get(meshComponents[i].id);
			toDraw.push_back(std::make_tuple(&meshComponents[i], pTransformComponent));
		}
	}
	for(const auto& toDrawTuple : toDraw)
	{
		const MeshComponent* meshComponent = std::get<0>(toDrawTuple);
		const TransformComponent* transform = std::get<1>(toDrawTuple);
		Matrix4x4 modelMatrix;
		modelMatrix = modelMatrix.Translate(transform->position);
		modelMatrix = modelMatrix.Rotate(transform->rotation);
		modelMatrix = modelMatrix.Scale(transform->scale);
		pRender->DrawMesh(meshComponent->meshId, modelMatrix);
	}
	pRender->Present();
}